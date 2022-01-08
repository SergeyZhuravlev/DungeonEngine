mkdir .build
chdir .build

cmake -A Win32 ..
::cmake --build ".." --target test_hello_world

cd ..

pause