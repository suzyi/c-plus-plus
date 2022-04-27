cmake_minimum_required(VERSION 3.5)

set(glog_LIBRARIES "C:/Users/me/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/lib/glogd.lib")
include_directories("C:/Users/me/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/include")

project(glog_project)
add_executable(glog_exe
    main.cpp
)
target_link_libraries(glog_exe ${glog_LIBRARIES})