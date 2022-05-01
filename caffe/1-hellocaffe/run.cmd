if EXIST build rm -rf build
mkdir build
cd build
cmake .. -A x64
cmake --build . --config Release
Release\hellocaffe.exe
