#!/bin/bash
# Local mirror of the GitHub CI build: compiles the library, builds the
# unit tests and runs them. Run this before pushing, it catches failures
# here instead of burning CI runs.
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"

QMAKE=""
for candidate in qmake6 qmake-qt6 qmake; do
  if command -v "${candidate}" >/dev/null 2>&1; then
    QMAKE="${candidate}"
    break
  fi
done

if [[ -z "${QMAKE}" ]]; then
  echo "Error: qmake not found. Run scripts/linux/deps.sh first." >&2
  exit 1
fi

echo "Using qmake: ${QMAKE}"

LIB_BUILD_DIR="${ROOT_DIR}/build-ci-check-lib"
TEST_BUILD_DIR="${ROOT_DIR}/build-ci-check-test"
mkdir -p "${LIB_BUILD_DIR}" "${TEST_BUILD_DIR}"

echo "Building qt-plus..."
(cd "${LIB_BUILD_DIR}" && "${QMAKE}" "${ROOT_DIR}/qt-plus.pro" CONFIG+=release)
make -C "${LIB_BUILD_DIR}" -j"$(nproc)"

echo "Building tests..."
(cd "${TEST_BUILD_DIR}" && "${QMAKE}" "${ROOT_DIR}/test/qt-plus-test.pro" CONFIG+=release)
make -C "${TEST_BUILD_DIR}" -j"$(nproc)"

echo "Running tests..."
(cd "${ROOT_DIR}/test" && LD_LIBRARY_PATH="${ROOT_DIR}/bin" QT_QPA_PLATFORM=offscreen "${ROOT_DIR}/bin/qt-plus-test")

echo "Local CI check passed."
