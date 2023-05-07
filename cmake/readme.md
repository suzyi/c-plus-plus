### 1 - command line, variables and functions
+ command line
  + cmake
    + `cmake -G "Your Generator" path/to/your/source`
    + `cmake -G "Visual Studio 16 2019" -A Win32 -S path/to/your/source -B "buildFolder"` or `cmake -G "Visual Studio 16 2019" -A x64 -S \path_to_source\ -B "buildFolder"`
      + `-G` specifies the Generator. Options: `Visual Studio 16 2019`, `Visual Studio 14 2015`, `Visual Studio 12 2013` and so on.
      + `-A` specifies the type. Options: `Win32`, `x64`.
      + `-B` specifies the output folder, which is commonly named `build`.
      + `-S` specifies the folder where `main.cpp` is at.
    + `cmake .. -C C:\Users\me\.caffe\dependencies\libraries_v140_x64_py27_1.1.0\libraries\caffe-builder-config.cmake`
    + `cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch "Visual Studio 16 2019 Win64" ..` or `cmake "Visual Studio 16 2019 Win64" ..`
      + `cmake -DCMAKE_PREFIX_PATH=C:\Users\me\.caffe\dependencies\libraries_v140_x64_py27_1.1.0\libraries ..`
      + `cmake -G "Visual Studio 16 2019 Win64" ..`
      + `cmake -G Ninja ..`
    + `cmake --build .`
      + `cmake --build build32 --config Release` or `cmake --build build64 --config Release`
      + `cmake --build . --config Release` or `Debug`
      + `cmake --build . --target runtest --config Debug`
+ variables
  + CMAKE_BINARY_DIR: The root or top level folder that you run the cmake command from is known as your CMAKE_BINARY_DIR and is the root folder for all your binary files. For example, in the project [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library), the CMAKE_BINARY_DIR is `C-static-library/build`.
  + CMAKE_CURRENT_BINARY_DIR:
  + CMAKE_CURRENT_SOURCE_DIR:
  + CMAKE_GENERATOR
    + `set CMAKE_GENERATOR=Visual Studio 12 2013 Win64`, `set CMAKE_GENERATOR=Visual Studio 14 2015 Win64`, or `set CMAKE_GENERATOR=Ninja`
  + CMAKE_PREFIX_PATH
    + In the libtorch project "print_tensor", we run the command
`cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch -DCMAKE_BUILD_TYPE=Release "Visual Studio 16 2019 Win64" ..` to tell cmake where TorchConfig.cmake can be found. According to [CMAKE_PREFIX_PATH.html](https://cmake.org/cmake/help/v3.0/variable/CMAKE_PREFIX_PATH.html), CMAKE_PREFIX_PATH is a path used for searching by FIND_XXX(), with appropriate suffixes added. To be specific, CMAKE_PREFIX_PATH contains the “base” directories, 
      + the FIND_PROGRAM() adds /bin to each of the directories in the path, 
      + FIND_LIBRARY() appends /lib to each of the directories, 
      + and FIND_PATH() and FIND_FILE() append /include . 
      + By default it is empty, it is intended to be set by the project.
  
  + CMAKE_SOURCE_DIR:
  + ThirdPartyPackage_DIR, Torch_DIR and OpenCV_DIR for example under which you can find "TorchConfig.cmake" and "OpenCVConfig.cmake", respectively.
  + ThirdPartyPackage_FOUND
    + `if(Boost_FOUND) message ("boost found") include_directories(${Boost_INCLUDE_DIRS}) else() message (FATAL_ERROR "Cannot find Boost") endif()`
  + PROJECT_BINARY_DIR:
  + PROJECT_SOURCE_DIR: For example, in the project [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library), the PROJECT_SOURCE_DIR is the directory `C-static-library`.
  + MSVC: Set to true when the compiler is some version of Microsoft Visual C++.
  

+ functions
  + add_definitions()
    + `add_definitions(-DTEST_DEBUG)`
      + In a anaconda prompt, `cmake -DTEST_DEBUG=1 ..`.
      + In a .cpp file, `#ifdef TEST_DEBUG #else #endif`
  + add_executable()
    + `add_executable(gflags_exe src/main.cpp)`
  + add_library()
    + By running `add_library(library_name STATIC src/Hello.cpp)`, "library_name.lib" will be generated and placed to the directory "project_name/build/Debug/".
  + `add_subdirectory(source_dir)`. Adds a subdirectory to the build. The source_dir specifies the directory in which the source CMakeLists.txt and code files are located.
    + `add_subdirectory(src/caffe)`
    + `add_subdirectory(tools)`
    + `add_subdirectory(examples)`
  + cmake_minimum_required(VERSION 3.5)
  + file()
    + `file(COPY ${Caffe_DLL_DIR} DESTINATION Release)` will copy all files (.dll files included) from ${Caffe_DLL_DIR} to "Release."
  + [find_package()](https://github.com/suzyi/cpp/blob/master/cmake/basics.md#4---how-does-find_package-work)
    + `find_package(glog REQUIRED NO_MODULE)`, where `NO_MODULE` option specifies to find in the Config mode.
    + `PackageName_FOUND` (e.g., `Caffe_FOUND`) will be set to indicate whether the package was found. When the package is found, some other variables (e.g., `Caffe_INCLUDE_DIRS`, `Caffe_DEFINITIONS` and so on) may be set by the package itself.
    + two modes
      + In Module mode, CMake searches for a file called `Find\<PackageName\>.cmake`. The file is first searched in the `CMAKE_MODULE_PATH`, then secondly among the Find Modules provided by the CMake installation. If the file is found, CMake will execute the .cmake file.
      + If the package is not found under Module mode, cmake searches again using Config mode. A user may set the variable `CMAKE_FIND_PACKAGE_PREFER_CONFIG` to `TRUE` to direct CMake first search using Config mode before falling back to Module mode. Or alternatively, `find_package(glog REQUIRED NO_MODULE)`.
        + `cmake -DCMAKE_PREFIX_PATH=D:\libtorch-win-debug-1.8.1-cpu\libtorch -DCMAKE_BUILD_TYPE=Release "Visual Studio 16 2019 Win64" ..`
        + `find_package(OpenCV PATHS "D:/opencv-4.5.1/opencv/build/x64/vc15/lib" NO_DEFAULT_PATH)` and then use `cmake "Visual Studio 16 2019 Win64" ..`
        + `set(OpenCV_DIR "D:/opencv-4.5.1/opencv/build/x64/vc15/lib")` and then `find_package(OpenCV REQUIRED)`
  + `include(cmake/Utils.cmake)` loads and runs Cmake code from the file given.
  + `include_directories(${Caffe_DIR}/include)` or `include_directories("D:/libcaffe/caffe-windows/include")`. After this, the compiler will search in these directories for header files.
    + "caffe.hpp", "blob.hpp" and so on can be found in the path "D:/libcaffe/caffe-windows/include".
  + `link_directories()` adds the paths in which the linker should search for libraries.
    + For example, `link_directories("C:/Users/me/.caffe/dependencies/libraries_v140_x64_py27_1.1.0/libraries/lib")` tells the linker where these libraries "gflags.dll", "gflags.lib", "gflagsd.dll" and "gflagsd.lib" are placed.
  + list
    + `set (list_test a b c d) # create a list list_test="a;b;c;d"`, then `list(APPEND list_test 1 2 3 4)` results in `list_test="a;b;c;d;1;2;3;4"`
  + message
    + `message("Caffe_INCLUDE_DIRS: ${Caffe_INCLUDE_DIRS}")`
    + `message(FATAL_ERROR "MSVC: ${MSVC}, COPY_PREREQUISITES: ${COPY_PREREQUISITES}")`
  + project(project_name)
  + set
    + `set(OpenCV_DIR "D:/opencv-4.5.1/opencv/build/x64/vc15/lib")`, so that there is a "OpenCVConfig.cmake" under the directory OpenCV_DIR.
    + `set(var a b c d)` will result in a list `"a;b;c;d"`. `set (var "a b c d")` returns a single variable `"a c c d"`.
  + `set_target_properties (hello_static PROPERTIES OUTPUT_NAME "hello")` will change the output name from "hello_static.lib" to "hello.lib"
  + target_include_directories()
    + Basically works the same purpose as `include_directories()`
  + target_link_libraries()
    + `target_link_libraries(hellocaffe ${Caffe_LIBRARIES})`, where `hellocaffe` must have been created by a command such as `add_executable(hellocaffe main.cpp)`.
    + `target_link_libraries(bgr2gray ${OpenCV_LIBRARIES})`, where `bgr2gray` is created via `add_executable(bgr2gray main.cpp)`.
      + `message("OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}")` gives `OpenCV_LIBRARIES: opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio;opencv_world`.
    + `target_link_libraries(gflags_example_exe gflagsd.lib)`

### 2 - basics
+ [loop and file operation](examples/loop-and-file-operation.md)
+ [deploy a libtorch project on Visual Studio 2019 using cmake](https://github.com/suzyi/cpp/blob/master/deep-learning/libtorch.md)
+ [deploy a opencv project on Visual Studio 2019 using cmake](https://github.com/suzyi/cpp/blob/master/opencv/0-installation.md#2---run-a-toy-opencv-example-with-the-helpf-of-cmakeliststxt)
### 3 intro to a cpp project
Generally, three files (one .h header file and two .cpp files) are contained within a c++ project. The .h (header file) file simply declares needed classes for the project but doesn't constain further specific definition of functions and objects. Those specific definitions are written in a file like same-name-as-header.cpp. The second .cpp (often named as main.cpp) shows you how to call those classes to implement a certain task.

Here you can find a nice [project](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library) to demonstrate the relationship among Header.h, Hello.cpp and main.cpp, which is summarized as 
+ Header.h ---> Hello.cpp via target_include_directories, i.e., `target_include_directories(project_name PUBLIC ${PROJECT_SOURCE_DIR}/include)`, where Header.h is placed under the directory "${PROJECT_SOURCE_DIR}/include".
+ Hello.cpp --> .exe via target_link_libraries, i.e., `target_link_libraries(exe_name PRIVATE project_name)`. Alternatively, you can transform `Hello.cpp` to "Hello.lib" and then use `target_link_libraries(exe_name PRIVATE Hello.lib)`.
+ main.cpp ---> .exe via add_executable, i.e., `add_executable(exe_name src/main.cpp)`.
