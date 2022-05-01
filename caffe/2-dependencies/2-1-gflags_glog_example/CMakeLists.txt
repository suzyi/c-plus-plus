cmake_minimum_required(VERSION 3.5)

set(all_LIBRARIES "glogd.lib" "gflagsd.lib")
link_directories("C:/Users/me/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/lib")
include_directories("C:/Users/me/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/include")

project(gflags_glog_project)
add_executable(gflags_glog_exe
    main.cpp
)
target_link_libraries(gflags_glog_exe ${all_LIBRARIES})