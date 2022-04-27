cmake_minimum_required(VERSION 3.5)

set(gflags_LIBRARIES "gflagsd.lib")
link_directories("C:/Users/me/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/lib")
include_directories("C:/Users/me/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/include/gflags")

project(gflags_project)
add_executable(gflags_exe
    main.cpp
)
target_link_libraries(gflags_exe ${gflags_LIBRARIES})