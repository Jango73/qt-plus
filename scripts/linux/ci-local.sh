#!/bin/bash
# Local mirror of the GitHub CI build: builds the project and runs its checks.
# Run this before pushing, it catches failures here instead of burning CI runs.
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

echo "[ci-local] Building (${BUILD_TYPE})..."
"${SCRIPT_FOLDER}/build.sh" -c "${BUILD_TYPE}"

BUILD_FOLDER="${PROJECT_ROOT_FOLDER}/build-${BUILD_TYPE,,}"
LOG_FILE="${PROJECT_ROOT_FOLDER}/tmp/ci-local.log"

if [[ "${BUILD_TYPE}" == "Debug" ]]; then
  BINARY="${BUILD_FOLDER}/test/qt-plus-testd"
else
  BINARY="${BUILD_FOLDER}/test/qt-plus-test"
fi

if [ ! -f "${BINARY}" ]; then
  echo "[ci-local] Binary not found at ${BINARY}" >&2
  exit "${EXIT_FAILURE}"
fi

mkdir -p "$(dirname "${LOG_FILE}")"
echo "[ci-local] Running checks (logging to ${LOG_FILE})..."
QT_QPA_PLATFORM=offscreen "${BINARY}" 2>&1 | tee "${LOG_FILE}"

echo "[ci-local] Local CI check passed."
