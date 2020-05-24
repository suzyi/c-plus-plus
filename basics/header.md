### How to create your own header files in C/C++?
+ First, create a file named `myHeader.h` with content below
```
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
```
+ Second, include `myHeader.h` in your `main.cpp` file, i.e. `#include "myHeader.h"`
