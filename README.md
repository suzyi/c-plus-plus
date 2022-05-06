# c-plus-plus
Today is May 12, 2020. I begin to learn c++ from scratch.
### Why do I learn cpp?
+ Up to now, I've been using python for more than three years (from Dec 2016 to May 2020). So why do I begin to learn cpp? The major reason is that cpp is faster than python. For example, to solve the same problem (leetcode 1. Two Sum) with the save algorithm below, cpp costs 476ms while python consumes 4048 ms.
+ Part of Tensorflow is written in c++ and Tensorflow also provides stable API for c++ and python and unstable API for other languages.
### basics
+ `int a = 2147483647; // 0111 1111 1111 1111 1111 1111 1111 1111; int b = a << 1;     // 1111 1111 1111 1111 1111 1111 1111 1110` left shit operation
+ `const int a = 7;` tells the compiler that `a` is invariant. After that, `a = 8;` will lead to an error.
+ [cout](https://github.com/suzyi/cpp/blob/master/basics/cout.md): `std::cout<<std::endl;` vs `cout<<endl;`
+ [containers](https://github.com/suzyi/cpp/blob/master/basics/containers.md): array, bitset, deque, queue, stack, unordered_map, vector, pair.
+ `#if defined(USE_LEVELDB) && defined(USE_LMDB) #include <leveldb/write_batch.h> #include <lmdb.h> #endif`
+ ifdef, ifndef
  + `#ifdef CPU_ONLY Caffe::set_mode(Caffe::CPU); #else Caffe::set_mode(Caffe::GPU); #endif`
  + `#ifndef CAFFE_BLOB_HPP_, #define CAFFE_BLOB_HPP_, #endif  // CAFFE_BLOB_HPP_`. This can help avoid error caused by including the same header file.
+ `inline int Max (int a, int b) {if(a >b) return a;}`. `Inline` means inserting this piece of code to current position to improve efficiency, not calling it.
+ [loop and if and switch](https://github.com/suzyi/cpp/blob/master/basics/loop_if.md): for, while, if, switch, break, auto;
+ [pointer and reference](https://github.com/suzyi/cpp/blob/master/basics/pointer_reference.md): &, *
  + [LinkedList.cpp](https://github.com/suzyi/cpp/blob/master/basics/LinkedList.cpp)
  + [linkedlist](https://github.com/suzyi/cpp/blob/master/leetcode/linkedlist.md)[leetcode-linkedlist](https://github.com/suzyi/cpp/blob/master/leetcode/linkedlist.md)
+ comment and uncomment: ctrl+/
+ `i++` vs `++i`: If `int i=0; string s="abc";`, then `cout<<s[i++]<<", i="<<i<<endl;` outputs `a, i=1` and `i=0; cout<<s[++i]<<", i="<<i<<endl;` outputs `b, i=1`.
+ [struct and class](https://github.com/suzyi/cpp/blob/master/basics/struct_class.md).
+ typedef
  + `typedef char char_fixed_len[81];`, then use `char_fixed_len var1, var2` to define two variables sharing the same length 81.
  + `typedef char * pstr; pstr str = "abc";`
  + `void printHello(int i);` defines a function. 
    + A normal way to declare a function pointer is `void (*pFunc)(int);`, which can then be used via `pFunc = &printHello; (*pFunc)(110);`.
    + An alternative way is `typedef void (*PrintHelloHandle)(int);`, followed by `PrintHelloHandle pFunc; pFunc = &printHello; (*pFunc)(110);`, and `PrintHelloHandle pFuncOther;`
+ [common functions](https://github.com/suzyi/cpp/blob/master/basics/common_functions.md): sort, accumulate
+ [data types](https://github.com/suzyi/cpp/blob/master/basics/data_types.md): int, bool, string, char, auto
+ file types (Generally, a c++ project usually contains a .h file and two .cpp files where .h makes a simple definition for all classes, one .cpp makes specific definition and operations for all those class, and the remaining .cpp is typically named as main.cpp to execute a certain task by calling those defined classes.)
  + [.h header files](https://github.com/suzyi/cpp/blob/master/basics/header.md): How to create your own header (.h) files in C/C++?
  + [.cpp]
  + library
    + static library [windows .lib, linux .a]: static libraries. .LIB files can be either static libraries (containing object files) or import libraries (containing symbols to allow the linker to link to a DLL). Libraries are used because you may have code that you want to use in many programs. For example if you write a function that counts the number of characters in a string, that function will be useful in lots of programs. Once you get that function working correctly you don't want to have to recompile the code every time you use it, so you put the executable code for that function in a library, and the linker can extract and insert the compiled code into your program. Static libraries are sometimes called 'archives' for this reason.
    + shared library [windows .dll, linux .so, macOS .dylib]: dynamic libraries. Dynamic libraries take this one step further. It seems wasteful to have multiple copies of the library functions taking up space in each of the programs. Why can't they all share one copy of the function? This is what dynamic libraries are for. Rather than building the library code into your program when it is compiled, it can be run by mapping it into your program as it is loaded into memory. Multiple programs running at the same time that use the same functions can all share one copy, saving memory.
  + [.pdb]
+ [::](basics/scope-resolution-operator.md): This is scope resolution operator.
+ [constructor and destructor](basics/constructor_and_destructor.md): Introduce the concept of constructor and destructor.
### advances
+ [template](advances/template/readme.md)
### third-party package
+ [cmake](cmake/readme.md): install cmake, and deploy libtorch and OpenCV on Visual Studio 2019.
+ [print_hello_world](cmake/examples/print_hello_world/): use cmake to call VS generator to generate a .exe file.
+ [read_txt](cmake/examples/read_txt/): Print contents of a .txt file line by line.
+ [libtorch](https://github.com/suzyi/cpp/blob/master/deep-learning/libtorch.md): download the libtorch and deploy it on Visual Studio 2019 and then run a simple example called "print_tensor".
+ [opencv](https://github.com/suzyi/cpp/blob/master/deep-learning/opencv.md): install opencv, and deploy it on Visual Studio 2019 and then run a simple example called "bgr2gray".
+ [caffe](caffe): install caffe, and implement several deep learning tasks.
### leetcode
+ [top-100-liked-questions](https://github.com/suzyi/cpp/blob/master/leetcode/top-100-liked-questions.md)
+ [dynamic-programming](https://github.com/suzyi/cpp/blob/master/leetcode/dynamic-programming.md)
+ [linkedlist](https://github.com/suzyi/cpp/blob/master/leetcode/linkedlist.md)
### projects
+ Sorting Algorithm
+ Logistic Regression
### tools
+ compiler
  + A compiler is a tool that helps us compile and run a .cpp file.
  + The difference between GCC and Visual Studio 2019. 
    + GCC is a compiler. Instead of using GCC, Visual Studio 2019 (or 2013 etc) has its own comliper.
  + The difference between QT and Visual Studio 2019. 
    + Both QT and VS 2019 are developing tools. They can replace each other in some basic functions.
### Questions
I am still confused with the questions below: