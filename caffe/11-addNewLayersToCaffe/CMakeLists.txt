cmake_minimum_required(VERSION 2.8.8)
include("C:/Users/suzy/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/caffe-builder-config.cmake")
find_package(Caffe)
set(Caffe_DIR "F:/caffe/build")
project(mseErrorViaCaffe_proj)
link_directories("F:/caffe/build/lib/Release")

set(Caffe_INCLUDE_DIRS "F:/caffe/build/include" "F:/caffe/build" "F:/caffe/include")
include_directories(${Caffe_INCLUDE_DIRS})
add_executable(mseErrorViaCaffe main.cpp)
target_link_libraries(mseErrorViaCaffe ${Caffe_LIBRARIES})

set(Caffe_DLL_DIR "F:/caffe/build/install/bin/")
file(COPY ${Caffe_DLL_DIR} DESTINATION Release)