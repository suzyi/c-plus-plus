# c-plus-plus
Today is May 12, 2020. I begin to learn c++ from scratch.
### Why do I learn cpp?
+ Up to now, I've been using python for more than three years (from Dec 2016 to May 2020). So why do I begin to learn cpp? The major reason is that cpp is faster than python. For example, to solve the same problem (leetcode 1. Two Sum) with the save algorithm below, cpp costs 476ms while python consumes 4048 ms.
+ Part of Tensorflow is written in c++ and Tensorflow also provides stable API for c++ and python and unstable API for other languages.
### Online Programming Platform
+ http://www.dooccn.com/cpp/ (unable to compile `unordered_map`), https://www.tutorialspoint.com/compile_cpp_online.php
### basics
+ [cout](https://github.com/suzyi/cpp/blob/master/basics/cout.md): `std::cout<<std::endl;` vs `cout<<endl;`
+ [containers](https://github.com/suzyi/cpp/blob/master/basics/containers.md): vector, unordered_map, stack.
+ [loop and if](https://github.com/suzyi/cpp/blob/master/basics/loop_if.md): for, while, if
+ [pointer and reference](https://github.com/suzyi/cpp/blob/master/basics/pointer_reference.md): &, *
+ comment and uncomment: ctrl+/
+ `i++` vs `++i`: If `int i=0; string s="abc";`, then `cout<<s[i++]<<", i="<<i<<endl;` outputs `a, i=1` and `i=0; cout<<s[++i]<<", i="<<i<<endl;` outputs `b, i=1`.
+ [struct and class](https://github.com/suzyi/cpp/blob/master/basics/struct_class.md).
### leetcode
+ [top-100-liked-questions](https://github.com/suzyi/cpp/blob/master/leetcode/top-100-liked-questions.md)
+ [dynamic-programming](https://github.com/suzyi/cpp/blob/master/leetcode/dynamic-programming.md)
### projects
### Questions
I am still confused with the questions below:
+ `vector<int> twoSum(vector<int>& nums, int target)` defines a function named twoSum over the variables nums and target, why do they use `& nums` instead of `nums`?
+ How do I outputs each element of an unordered_map? Maybe it's related to `auto`?
