if [ -e build ];then
    rm -rf build
fi
mkdir build
cd build
cmake -A x64 ..
cmake --build . --config Release
cd ..

exe=build/Release/read_txt.exe
${exe}
