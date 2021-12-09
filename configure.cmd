mkdir .build
chdir .build

cmake -A Win32 ..
::cmake --build ".." --target hello_world

cd ..

pause