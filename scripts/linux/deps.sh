#!/bin/bash
set -euo pipefail

APT_PACKAGES=(
  build-essential
  cmake
  ninja-build
  git
  qt6-base-dev
  qt6-base-dev-tools
  qt6-declarative-dev
  qt6-declarative-dev-tools
  qt6-qmltooling-plugins
  qt6-tools-dev
  qt6-tools-dev-tools
  linguist-qt6
  libqt6shadertools6-dev
  qt6-shader-baker
  qt6-wayland
  # NOTE: qtcreator is excluded on purpose. On Ubuntu 22.04 (jammy) the
  # unversioned qtcreator package (6.0.2) is Qt5-based and pulls libqt5*,
  # qml-module-*, qt5-doc and related packages as dependencies.
  # Install an IDE separately only if needed.
  qml6-module-qtquick
  qml6-module-qtquick-controls
  qml6-module-qtquick-layouts
  qml6-module-qtqml-models
  qml6-module-qtqml-workerscript
  qml6-module-qtquick-templates
  qml6-module-qtquick-window
  libqt6serialport6-dev
)

if ! command -v apt-get >/dev/null 2>&1; then
  echo "apt-get not found. This script is for Debian/Ubuntu-based systems." >&2
  exit 1
fi

sudo apt-get update
sudo apt-get install -y "${APT_PACKAGES[@]}"