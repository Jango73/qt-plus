#!/bin/bash
# Code complexity report with scc (https://github.com/boyter/scc).
set -euo pipefail

SCRIPT_FOLDER="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT_FOLDER="$(cd "${SCRIPT_FOLDER}/../.." && pwd)"

(cd "${PROJECT_ROOT_FOLDER}" && scc source/cpp \
  --exclude-dir source/cpp/GeoTools/ \
  --exclude-dir source/cpp/Poppy/ \
  --exclude-dir source/cpp/rsa/ \
  --by-file --sort complexity --format html > quality.html)
