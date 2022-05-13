#!/bin/sh

mkdir -p build

g++ -Wall -g -c -o build/libmodulea-static.o module_a.c
g++ -Wall -g -c -o build/libmoduleb-static.o module_b.c

# Create static library.

ar rcs build/libmodulea-static.a build/libmodulea-static.o
ar rcs build/libmoduleb-static.a build/libmoduleb-static.o


# Compile demo_use program file.

g++ -Wall -g -c main.cpp -o build/main.o

g++ -g -o build/app build/main.o -L./build -lmodulea-static -lmoduleb-static

echo "Target in src/build directory"

# Execute the program.

#./main 100
