if EXIST build rm -rf build
mkdir build
cd build
cmake -A x64 ..
cmake --build . --config Debug
Debug\gflags_glog_exe.exe --width=32 --height=32
:: Debug\gflags_glog_exe.exe --width=128 --height=64