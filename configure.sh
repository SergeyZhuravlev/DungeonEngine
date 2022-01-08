#!/bin/bash

mkdir .build
cd .build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
#cmake --build ".." --target test_hello_world

cd ..

read -p "Press enter to continue"