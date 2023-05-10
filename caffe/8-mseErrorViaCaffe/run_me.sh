if [ -e build ];then
rm -rf build
fi
mkdir build
cd build
cmake -G "Visual Studio 14 2015" -A x64 -S .. -B .
cmake --build . --config Release
cd ..
build/Release/mseErrorViaCaffe.exe