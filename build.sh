#!/bin/sh

cd "$(dirname "$0")"

echo "Creating build directory..."
mkdir -p build && cd build

echo "Running cmake..."
cmake ..

echo "Building..."
cmake --build . --config Release
