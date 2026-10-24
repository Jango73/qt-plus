#!/bin/bash
set -euo pipefail

SCRIPT_FOLDER="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT_FOLDER="$(cd "${SCRIPT_FOLDER}/../.." && pwd)"
VERSION_FILE="${PROJECT_ROOT_FOLDER}/VERSION"
QMAKE_PRO="${PROJECT_ROOT_FOLDER}/qt-plus.pro"
CMAKE_LISTS="${PROJECT_ROOT_FOLDER}/CMakeLists.txt"
GLOBAL_H="${PROJECT_ROOT_FOLDER}/source/cpp/qtplus_global.h"

EXIT_SUCCESS=0
EXIT_FAILURE=1
VERSION_PATTERN='^[0-9]+\.[0-9]+\.[0-9]+$'

usage() {
  cat <<'USAGE'
Usage: ./release-version.sh

Interactive flow:
1. Show current version
2. Prompt for new version
3. Allow cancellation
4. Update version files (VERSION, qt-plus.pro, CMakeLists.txt,
   source/cpp/qtplus_global.h)
5. Create commit and tag v<version>
USAGE
}

ensure_git_repository() {
  if ! git -C "${PROJECT_ROOT_FOLDER}" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    echo "This script must be run inside a Git repository." >&2
    exit "${EXIT_FAILURE}"
  fi
}

ensure_clean_worktree() {
  if [[ -n "$(git -C "${PROJECT_ROOT_FOLDER}" status --short)" ]]; then
    echo "Git worktree is not clean. Commit or stash existing changes before releasing a version." >&2
    exit "${EXIT_FAILURE}"
  fi
}

ensure_version_file_exists() {
  if [[ ! -f "${VERSION_FILE}" ]]; then
    echo "Version file not found: ${VERSION_FILE}" >&2
    exit "${EXIT_FAILURE}"
  fi
}

read_current_version() {
  tr -d '[:space:]' < "${VERSION_FILE}"
}

prompt_new_version() {
  local current_version="$1"
  local candidate_version=""

  printf 'Current version: %s\n' "${current_version}" >&2
  read -r -p "New version (empty to cancel): " candidate_version

  if [[ -z "${candidate_version}" ]]; then
    echo "Operation cancelled." >&2
    exit "${EXIT_SUCCESS}"
  fi

  if [[ "${candidate_version}" == "cancel" ]]; then
    echo "Operation cancelled." >&2
    exit "${EXIT_SUCCESS}"
  fi

  if [[ ! "${candidate_version}" =~ ${VERSION_PATTERN} ]]; then
    echo "Invalid version: ${candidate_version}" >&2
    echo "Expected format: MAJOR.MINOR.PATCH (e.g. 3.1.0)" >&2
    exit "${EXIT_FAILURE}"
  fi

  if [[ "${candidate_version}" == "${current_version}" ]]; then
    echo "New version matches the current version." >&2
    exit "${EXIT_FAILURE}"
  fi

  printf '%s\n' "${candidate_version}"
}

confirm_tag_overwrite() {
  local new_version="$1"
  local tag_name="v${new_version}"
  local answer=""

  if ! git -C "${PROJECT_ROOT_FOLDER}" rev-parse --verify --quiet "refs/tags/${tag_name}" >/dev/null; then
    return 0
  fi

  read -r -p "Tag ${tag_name} already exists. Overwrite? [y/N]: " answer
  if [[ "${answer,,}" == "y" || "${answer,,}" == "yes" ]]; then
    return 0
  fi

  echo "Operation cancelled." >&2
  exit "${EXIT_SUCCESS}"
}

update_version_files() {
  local new_version="$1"
  local major=""
  local rest=""
  local minor=""
  local patch=""

  major="${new_version%%.*}"
  rest="${new_version#*.}"
  minor="${rest%%.*}"
  patch="${rest#*.}"

  for f in "${VERSION_FILE}" "${QMAKE_PRO}" "${CMAKE_LISTS}" "${GLOBAL_H}"; do
    if [[ ! -f "${f}" ]]; then
      echo "Missing file: ${f}" >&2
      exit "${EXIT_FAILURE}"
    fi
  done

  printf '%s\n' "${new_version}" > "${VERSION_FILE}"

  sed -i -E "s/^VERSION = .*/VERSION = ${new_version}/" "${QMAKE_PRO}"
  grep -q "^VERSION = ${new_version}$" "${QMAKE_PRO}"

  sed -i -E "s/^project\(qt-plus VERSION [0-9]+\.[0-9]+\.[0-9]+/project(qt-plus VERSION ${new_version}/" "${CMAKE_LISTS}"
  grep -q "^project(qt-plus VERSION ${new_version} LANGUAGES CXX)$" "${CMAKE_LISTS}"

  sed -i -E "s/^#define QTPLUS_VERSION_MAJOR .*/#define QTPLUS_VERSION_MAJOR ${major}/" "${GLOBAL_H}"
  sed -i -E "s/^#define QTPLUS_VERSION_MINOR .*/#define QTPLUS_VERSION_MINOR ${minor}/" "${GLOBAL_H}"
  sed -i -E "s/^#define QTPLUS_VERSION_PATCH .*/#define QTPLUS_VERSION_PATCH ${patch}/" "${GLOBAL_H}"
  sed -i -E "s/^#define QTPLUS_VERSION_STR .*/#define QTPLUS_VERSION_STR \"${new_version}\"/" "${GLOBAL_H}"
  grep -q "^#define QTPLUS_VERSION_MAJOR ${major}$" "${GLOBAL_H}"
  grep -q "^#define QTPLUS_VERSION_MINOR ${minor}$" "${GLOBAL_H}"
  grep -q "^#define QTPLUS_VERSION_PATCH ${patch}$" "${GLOBAL_H}"
  grep -q "^#define QTPLUS_VERSION_STR \"${new_version}\"$" "${GLOBAL_H}"
}

ensure_version_changed() {
  if git -C "${PROJECT_ROOT_FOLDER}" diff --quiet --exit-code; then
    echo "No file was updated. Aborting release." >&2
    exit "${EXIT_FAILURE}"
  fi
}

create_release_commit_and_tag() {
  local new_version="$1"
  local tag_name="v${new_version}"

  git -C "${PROJECT_ROOT_FOLDER}" add -A
  git -C "${PROJECT_ROOT_FOLDER}" commit -m "Release ${new_version}"
  git -C "${PROJECT_ROOT_FOLDER}" tag -f "${tag_name}"

  printf 'Created commit and tag %s\n' "${tag_name}"
}

main() {
  if [[ "${1:-}" == "-h" || "${1:-}" == "--help" ]]; then
    usage
    exit "${EXIT_SUCCESS}"
  fi

  if [[ $# -ne 0 ]]; then
    usage >&2
    exit "${EXIT_FAILURE}"
  fi

  ensure_git_repository
  ensure_clean_worktree
  ensure_version_file_exists

  local current_version=""
  local new_version=""

  current_version="$(read_current_version)"
  new_version="$(prompt_new_version "${current_version}")"

  confirm_tag_overwrite "${new_version}"
  update_version_files "${new_version}"
  ensure_version_changed
  create_release_commit_and_tag "${new_version}"
}

main "$@"
