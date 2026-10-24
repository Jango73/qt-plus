#!/bin/bash
# Single source of truth for the release: the VERSION file at repo root.
# This script syncs it to qt-plus.pro (qmake) and qtplus_global.h.
# CMakeLists.txt reads the VERSION file at configure time, so it needs no edit.
set -euo pipefail

SCRIPT_FOLDER="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT_FOLDER="$(cd "${SCRIPT_FOLDER}/../.." && pwd)"

EXIT_SUCCESS=0
EXIT_FAILURE=1

TAG=0

usage() {
  cat <<'USAGE'
Usage: ./set-version.sh [--tag] <version>
  --tag  create git tag v<version> after updating the files
Example: ./set-version.sh 1.2.3
Example: ./set-version.sh --tag 1.2.3
USAGE
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --tag)
      TAG=1
      shift
      ;;
    -h|--help)
      usage
      exit "${EXIT_SUCCESS}"
      ;;
    -*)
      echo "Unknown option: ${1}" >&2
      usage >&2
      exit "${EXIT_FAILURE}"
      ;;
    *)
      break
      ;;
  esac
done

if [[ $# -ne 1 ]]; then
  usage >&2
  exit "${EXIT_FAILURE}"
fi

NEW_VERSION="$1"

if [[ ! "${NEW_VERSION}" =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
  echo "Invalid version: ${NEW_VERSION} (expected X.Y.Z)" >&2
  exit "${EXIT_FAILURE}"
fi

MAJOR="${NEW_VERSION%%.*}"
REST="${NEW_VERSION#*.}"
MINOR="${REST%%.*}"
PATCH="${REST#*.}"

VERSION_FILE="${PROJECT_ROOT_FOLDER}/VERSION"
QMAKE_PRO="${PROJECT_ROOT_FOLDER}/qt-plus.pro"
GLOBAL_H="${PROJECT_ROOT_FOLDER}/source/cpp/qtplus_global.h"

for f in "${QMAKE_PRO}" "${GLOBAL_H}"; do
  if [[ ! -f "${f}" ]]; then
    echo "Missing file: ${f}" >&2
    exit "${EXIT_FAILURE}"
  fi
done

printf '%s\n' "${NEW_VERSION}" > "${VERSION_FILE}"

sed -i -E "s/^VERSION = .*/VERSION = ${NEW_VERSION}/" "${QMAKE_PRO}"
grep -q "^VERSION = ${NEW_VERSION}$" "${QMAKE_PRO}"

sed -i -E "s/^#define QTPLUS_VERSION_MAJOR .*/#define QTPLUS_VERSION_MAJOR ${MAJOR}/" "${GLOBAL_H}"
sed -i -E "s/^#define QTPLUS_VERSION_MINOR .*/#define QTPLUS_VERSION_MINOR ${MINOR}/" "${GLOBAL_H}"
sed -i -E "s/^#define QTPLUS_VERSION_PATCH .*/#define QTPLUS_VERSION_PATCH ${PATCH}/" "${GLOBAL_H}"
sed -i -E "s/^#define QTPLUS_VERSION_STR .*/#define QTPLUS_VERSION_STR \"${NEW_VERSION}\"/" "${GLOBAL_H}"
grep -q "^#define QTPLUS_VERSION_MAJOR ${MAJOR}$" "${GLOBAL_H}"
grep -q "^#define QTPLUS_VERSION_MINOR ${MINOR}$" "${GLOBAL_H}"
grep -q "^#define QTPLUS_VERSION_PATCH ${PATCH}$" "${GLOBAL_H}"
grep -q "^#define QTPLUS_VERSION_STR \"${NEW_VERSION}\"$" "${GLOBAL_H}"

echo "Version set to ${NEW_VERSION} in:"
echo "  VERSION"
echo "  qt-plus.pro"
echo "  source/cpp/qtplus_global.h"

if [[ "${TAG}" -eq 1 ]]; then
  if git -C "${PROJECT_ROOT_FOLDER}" rev-parse "v${NEW_VERSION}" >/dev/null 2>&1; then
    echo "Tag v${NEW_VERSION} already exists" >&2
    exit "${EXIT_FAILURE}"
  fi
  git -C "${PROJECT_ROOT_FOLDER}" tag "v${NEW_VERSION}"
  echo "Created git tag v${NEW_VERSION}"
fi
