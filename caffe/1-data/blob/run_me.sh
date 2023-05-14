if [ ! -e build ];then
    mkdir build
fi
cd build
rm -rf *
cmake -G "Visual Studio 14 2015" -A x64 -S .. -B .
cmake --build . --config Release
cd ..
build/Release/blob.exe
