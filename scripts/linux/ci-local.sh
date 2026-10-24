#!/bin/bash
# Local mirror of the GitHub CI build: compiles the library, builds the
# unit tests and runs them. Run this before pushing, it catches failures
# here instead of burning CI runs.
set -euo pipefail

SCRIPT_FOLDER="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT_FOLDER="$(cd "${SCRIPT_FOLDER}/../.." && pwd)"

EXIT_SUCCESS=0
EXIT_FAILURE=1

usage() {
  cat <<'USAGE'
Usage: ./ci-local.sh [--debug|--release] [-d|-r] [-c Debug|Release] [-h|--help]
  --debug,   -d  Build type Debug
  --release, -r  Build type Release (default, same as CI)
  -c             Build type (Debug or Release)
USAGE
}

BUILD_TYPE="Release"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --debug|-d)
      BUILD_TYPE="Debug"
      shift
      ;;
    --release|-r)
      BUILD_TYPE="Release"
      shift
      ;;
    -c)
      if [[ -z "${2:-}" ]]; then
        echo "Option -c requires an argument." >&2
        usage >&2
        exit "${EXIT_FAILURE}"
      fi
      BUILD_TYPE="$2"
      shift 2
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

if [[ "${BUILD_TYPE}" != "Debug" && "${BUILD_TYPE}" != "Release" ]]; then
  echo "Invalid build type: ${BUILD_TYPE} (use Debug or Release)" >&2
  exit "${EXIT_FAILURE}"
fi

QMAKE=""
for candidate in qmake6 qmake-qt6 qmake; do
  if command -v "${candidate}" >/dev/null 2>&1; then
    QMAKE="${candidate}"
    break
  fi
done

if [[ -z "${QMAKE}" ]]; then
  echo "Error: qmake not found. Run scripts/linux/deps.sh first." >&2
  exit "${EXIT_FAILURE}"
fi

echo "Using qmake: ${QMAKE}"

if [[ "${BUILD_TYPE}" == "Debug" ]]; then
  QMAKE_CONFIG="debug"
else
  QMAKE_CONFIG="release"
fi

LIB_BUILD_DIR="${PROJECT_ROOT_FOLDER}/build-ci-check-lib"
TEST_BUILD_DIR="${PROJECT_ROOT_FOLDER}/build-ci-check-test"
mkdir -p "${LIB_BUILD_DIR}" "${TEST_BUILD_DIR}"

echo "Building qt-plus..."
(cd "${LIB_BUILD_DIR}" && "${QMAKE}" "${PROJECT_ROOT_FOLDER}/qt-plus.pro" "CONFIG+=${QMAKE_CONFIG}")
make -C "${LIB_BUILD_DIR}" -j"$(nproc)"

echo "Building tests..."
(cd "${TEST_BUILD_DIR}" && "${QMAKE}" "${PROJECT_ROOT_FOLDER}/test/qt-plus-test.pro" "CONFIG+=${QMAKE_CONFIG}")
make -C "${TEST_BUILD_DIR}" -j"$(nproc)"

echo "Running tests..."
(cd "${PROJECT_ROOT_FOLDER}/test" && LD_LIBRARY_PATH="${PROJECT_ROOT_FOLDER}/bin" QT_QPA_PLATFORM=offscreen "${PROJECT_ROOT_FOLDER}/bin/qt-plus-test")

echo "[ci-local] Local CI check passed."
