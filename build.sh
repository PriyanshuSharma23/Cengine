#!/bin/bash

# Set compiler and flags
CXX=g++
CXXFLAGS="-std=c++11 -Wall"

# Source directory
SRCDIR="src"

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

# Get a list of source files in the directory
src_files=$(find "$SRCDIR" -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \))

# Build the list of source files with spaces
src_list=""
for src_file in $src_files; do
    src_list+=" $src_file"
done

# Compile and link
$CXX $CXXFLAGS $src_list -o build/output

if [ $? -ne 0 ]; then
    echo "Build failed"
fi
