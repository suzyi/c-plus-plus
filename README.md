# c-plus-plus
Today is May 12, 2020. I begin to learn c++ from scratch.
### Why do I learn cpp?
+ Up to now, I've been using python for more than three years (from Dec 2016 to May 2020). So why do I begin to learn cpp? The major reason is that cpp is faster than python. For example, to solve the same problem (leetcode 1. Two Sum) with the save algorithm below, cpp costs 476ms while python consumes 4048 ms.
+ Part of Tensorflow is written in c++ and Tensorflow also provides stable API for c++ and python and unstable API for other languages.
### Local Programming Platform
+ download "Code Blocks" from http://www.codeblocks.org/home
  + Downloads -> Download the binary release -> codeblocks-20.03mingw-setup.exe
+ create a c file: New file -> save as .c
+ create a cpp file: File -> New -> Project -> Console application -> c++.
### Online Programming Platform
+ http://www.dooccn.com/cpp/ (unable to compile `unordered_map`)
+ https://www.tutorialspoint.com/compile_cpp_online.php
+ nowcoder OJ input-output exercises: https://ac.nowcoder.com/acm/contest/320#question
### basics
+ [cout](https://github.com/suzyi/cpp/blob/master/basics/cout.md): `std::cout<<std::endl;` vs `cout<<endl;`
+ [containers](https://github.com/suzyi/cpp/blob/master/basics/containers.md): array, bitset, deque, queue, stack, unordered_map, vector, pair.
+ [loop and if and switch](https://github.com/suzyi/cpp/blob/master/basics/loop_if.md): for, while, if, switch, break, auto;
+ [pointer and reference](https://github.com/suzyi/cpp/blob/master/basics/pointer_reference.md): &, *
+ comment and uncomment: ctrl+/
+ `i++` vs `++i`: If `int i=0; string s="abc";`, then `cout<<s[i++]<<", i="<<i<<endl;` outputs `a, i=1` and `i=0; cout<<s[++i]<<", i="<<i<<endl;` outputs `b, i=1`.
+ [struct and class](https://github.com/suzyi/cpp/blob/master/basics/struct_class.md).
+ [common functions](https://github.com/suzyi/cpp/blob/master/basics/common_functions.md): sort, accumulate
+ [data types](https://github.com/suzyi/cpp/blob/master/basics/data_types.md): int, bool, string, char, auto
+ file types
  + [.h header files](https://github.com/suzyi/cpp/blob/master/basics/header.md): How to create your own header (.h) files in C/C++?
  + [.lib]: static libraries. .LIB files can be either static libraries (containing object files) or import libraries (containing symbols to allow the linker to link to a DLL). Libraries are used because you may have code that you want to use in many programs. For example if you write a function that counts the number of characters in a string, that function will be useful in lots of programs. Once you get that function working correctly you don't want to have to recompile the code every time you use it, so you put the executable code for that function in a library, and the linker can extract and insert the compiled code into your program. Static libraries are sometimes called 'archives' for this reason.
  + [.dll]: dynamic libraries. Dynamic libraries take this one step further. It seems wasteful to have multiple copies of the library functions taking up space in each of the programs. Why can't they all share one copy of the function? This is what dynamic libraries are for. Rather than building the library code into your program when it is compiled, it can be run by mapping it into your program as it is loaded into memory. Multiple programs running at the same time that use the same functions can all share one copy, saving memory.
  + [.cpp]
  + [.pdb]
+ [::](https://github.com/suzyi/cpp/blob/master/basics/scope-resolution-operator.md): This is scope resolution operator.
+ [constructor and destructor](https://github.com/suzyi/cpp/blob/master/basics/constructor_and_destructor.md): Introduce the concept of constructor and destructor.
### cmake
+ [cmake](https://github.com/suzyi/cpp/blob/master/cmake/cmake.md)
+ [libtorch](https://github.com/suzyi/cpp/blob/master/deep-learning/libtorch.md): download the libtorch and deploy it on Visual Studio 2019 and then run a simple example.
+ [opencv](https://github.com/suzyi/cpp/blob/master/deep-learning/opencv.md): installation, examples.
### leetcode
+ [top-100-liked-questions](https://github.com/suzyi/cpp/blob/master/leetcode/top-100-liked-questions.md)
+ [dynamic-programming](https://github.com/suzyi/cpp/blob/master/leetcode/dynamic-programming.md)
### projects
+ Sorting Algorithm
+ Logistic Regression
### Questions
I am still confused with the questions below:
+ `vector<int> twoSum(vector<int>& nums, int target)` defines a function named twoSum over the variables nums and target, why do they use `& nums` instead of `nums`?
+ How do I outputs each element of an unordered_map? Maybe it's related to `auto`?
