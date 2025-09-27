#!/usr/bin/env bash
# Convenience script: configure, build, and run tests using CMake
set -euo pipefail
BUILD_DIR="build"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --parallel
ctest --output-on-failure
