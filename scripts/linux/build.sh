#!/bin/bash
set -euo pipefail

SCRIPT_FOLDER="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT_FOLDER="$(cd "${SCRIPT_FOLDER}/../.." && pwd)"

EXIT_SUCCESS=0
EXIT_FAILURE=1
VERBOSE_ENABLED=1
VERBOSE_DISABLED=0

BUILD_TYPE="Release"
VERBOSE_BUILD="${VERBOSE_DISABLED}"

usage() {
  cat <<'USAGE'
Usage: ./build.sh [--debug|--release] [-d|-r] [--verbose|-v] [-c Debug|Release] [-h|--help]
  --debug,   -d  Build type Debug
  --release, -r  Build type Release (default)
  --verbose, -v  Verbose build output
  -c             Build type (Debug or Release)
USAGE
}

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
    --verbose|-v)
      VERBOSE_BUILD="${VERBOSE_ENABLED}"
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

BUILD_DIR="${PROJECT_ROOT_FOLDER}/build-${BUILD_TYPE,,}"

# Find qmake executable (prefer Qt6)
QMAKE=""
for candidate in qmake6 qmake-qt6 qmake; do
  if command -v "${candidate}" >/dev/null 2>&1; then
    QMAKE="${candidate}"
    break
  fi
done

if [[ -z "${QMAKE}" ]]; then
  echo "Error: qmake not found. Install Qt development tools." >&2
  exit 1
fi

echo "Using qmake: ${QMAKE}"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

if [[ "${BUILD_TYPE}" == "Debug" ]]; then
  CONFIG_ARG="CONFIG+=debug"
else
  CONFIG_ARG="CONFIG+=release"
fi

echo "Building qt-plus with ${CONFIG_ARG}..."
"${QMAKE}" "${PROJECT_ROOT_FOLDER}/qt-plus.pro" "${CONFIG_ARG}"

if [ "${VERBOSE_BUILD}" -eq "${VERBOSE_ENABLED}" ]; then
  make -j"$(nproc)" VERBOSE=1
else
  make -j"$(nproc)"
fi

printf '\nBuilt qt-plus library in %s\n' "${PROJECT_ROOT_FOLDER}/bin"