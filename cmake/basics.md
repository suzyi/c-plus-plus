### basics
In this section, we use the ttroy50's [C-static-library](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library) to introduce you some basics about cmake, including add_library, target_include_directories, add_executable and target_link_libraries. But with a few modification to the file "CMakeLists.txt" to make it more understandable. We will split "CMakeLists.txt" below into several subsections to understand it.
```
# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

project(project_name)

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(library_name STATIC 
    src/Hello.cpp
)

target_include_directories(library_name
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(hello_binary 
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( hello_binary
    PRIVATE 
        library_name
)
```
#### add_library
By using the following sample code, you will see the file "library_name.lib" is generated and placed to the directory "project_name/build/Debug/".
```
# Generate the static library from the library sources
add_library(library_name STATIC 
    src/Hello.cpp
)
```
#### target_include_directories
The following code tells the library (i.e., the library_name.lib, or Hello.cpp) that where its needed header file is placed.
```
target_include_directories(library_name
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
```
#### add_executable
As we know, "main.cpp" performs a certain task and shows you how can we call all those defined classes in the header file. To make it runnable, the build-in command add_executable generates a hello_binary from "main.cpp". Then you can find it at "project_name/build/hello_binary" when the OS is Linux and "project_name/build/hello_binary.vcxproj" when OS is Windows 10.
```
add_executable(hello_binary 
    src/main.cpp
)
```
#### target_link_libraries
target_link_libraries is used to tell the .exe (also named as binary file or executable file) where the library (equivalent to the header file) is placed at.
```
# link the new hello_library target with the hello_binary target
target_link_libraries( hello_binary
    PRIVATE 
        library_name
)
```
