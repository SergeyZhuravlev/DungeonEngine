#!/bin/bash

mkdir .build
cd .build

cmake --build ".." --target test_hello_world

cd ..

read -p "Press enter to continue"