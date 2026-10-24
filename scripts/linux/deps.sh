#!/bin/bash
set -euo pipefail

SCRIPT_FOLDER="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT_FOLDER="$(cd "${SCRIPT_FOLDER}/../.." && pwd)"

EXIT_SUCCESS=0
EXIT_FAILURE=1

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

DNF_PACKAGES=(
  gcc-c++
  cmake
  ninja-build
  git
  qt6-qtbase-devel
  qt6-qtdeclarative-devel
  qt6-qttools-devel
  qt6-qtshadertools-devel
  qt6-qtwayland-devel
  qt6-qtserialport-devel
)

PACMAN_PACKAGES=(
  base-devel
  cmake
  ninja
  git
  qt6-base
  qt6-declarative
  qt6-tools
  qt6-shadertools
  qt6-wayland
  qt6-serialport
)

install_with_apt() {
  sudo apt-get update
  sudo apt-get install -y "${APT_PACKAGES[@]}"
}

install_with_dnf() {
  sudo dnf install "${DNF_PACKAGES[@]}"
}

install_with_pacman() {
  sudo pacman -S --needed "${PACMAN_PACKAGES[@]}"
}

main() {
  if command -v apt-get >/dev/null 2>&1; then
    install_with_apt
    return
  fi

  if command -v dnf >/dev/null 2>&1; then
    install_with_dnf
    return
  fi

  if command -v pacman >/dev/null 2>&1; then
    install_with_pacman
    return
  fi

  echo "Unsupported package manager. Supported package managers: apt-get, dnf, pacman." >&2
  exit 1
}

main
