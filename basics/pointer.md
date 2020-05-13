The sample code below may help you better understand the c++ pointer.
```
#include <iostream>
using namespace std;

int main() {
    int a=10;
    int *b=&a;
    cout << &a <<endl;
    cout << b <<endl;
    *b = 21;
    cout << a <<endl;
    return 0;
}
```
