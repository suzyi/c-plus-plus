std是一个命名空间（namespace)，‘::’是作用域运算符，cout是std空间中的一个函数名。使用cout时，必须有使用std命名空间的说明，有两种说明方式。

方式一：每次使用时对cout说明：
```
std::cout << "Input two numbers:";
```
方式二：在主函数前说明一下，后面就可以直接使用cout：
```
using namespace std;
cout << "Input two numbers:";
```
下面两段代码功能完全一样：

代码一：
```
#include <iostream>
 
int main()
{
     std::cout << "Hello world!!!" << std::endl;
     return 0;
}
```

代码二：
```
#include<iostream>
 
using namespace std;
 
int main()
{ 
    cout << "Hello world!!!" << endl;
    return 0;
}
```
