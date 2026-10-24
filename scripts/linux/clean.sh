#!/bin/bash
set -euo pipefail

SCRIPT_FOLDER="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT_FOLDER="$(cd "${SCRIPT_FOLDER}/../.." && pwd)"

EXIT_SUCCESS=0
EXIT_FAILURE=1

CLEAN_TARGET="all"

usage() {
  cat <<'USAGE'
Usage: ./clean.sh [--debug|--release|--all] [-d|-r|-a]
  --debug,   -d  Remove the debug build folder
  --release, -r  Remove the release build folder
  --all,     -a  Remove both build folders (default)
USAGE
}

remove_folder() {
  local target_folder="$1"
  if [ -d "${target_folder}" ]; then
    rm -rf "${target_folder}"
    printf 'Removed %s\n' "${target_folder}"
  else
    printf 'Skip %s (not found)\n' "${target_folder}"
  fi
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --debug|-d)
      CLEAN_TARGET="debug"
      shift
      ;;
    --release|-r)
      CLEAN_TARGET="release"
      shift
      ;;
    --all|-a)
      CLEAN_TARGET="all"
      shift
      ;;
    -h|--help)
      usage
      exit "${EXIT_SUCCESS}"
      ;;
    *)
      echo "Unknown option: ${1}" >&2
      usage >&2
      exit "${EXIT_FAILURE}"
      ;;
  esac
done

BUILD_DEBUG_FOLDER="${PROJECT_ROOT_FOLDER}/build-debug"
BUILD_RELEASE_FOLDER="${PROJECT_ROOT_FOLDER}/build-release"

case "${CLEAN_TARGET}" in
  debug)
    remove_folder "${BUILD_DEBUG_FOLDER}"
    ;;
  release)
    remove_folder "${BUILD_RELEASE_FOLDER}"
    ;;
  all)
    remove_folder "${BUILD_DEBUG_FOLDER}"
    remove_folder "${BUILD_RELEASE_FOLDER}"
    ;;
  *)
    echo "Invalid clean target: ${CLEAN_TARGET}" >&2
    exit "${EXIT_FAILURE}"
    ;;
esac
