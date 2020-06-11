`&`有3个作用--取地址、引用、按位与运算
+ 取地址：`int a=10; int *b=&a;`
+ 引用：`int a=1; int &a_nickname=a;`
+ 按位与运算：`A = 60; B = 13;` 则`A`、`B`的二进制分别是`A = 0011 1100; B = 0000 1101;` 所以`A & B = 0000 1100;`
  + 奇偶数判断：`if(A & 1==1) cout<<"A是奇数";`

`.` vs `->`
+ `Listnode head(-1);` then `head.next`.
+ `Listnode *slow = &head;` then `slow->next;`
### Sample Code for Pointer and Reference
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
The sample code below may help you better understand the c++ reference.
```
#include <iostream>
using namespace std;
void swap(int &p1, int &p2) { //int &p1=a; int &p2=b;
    int p=p1;
    p1=p2;
    p2=p;
}
int main() {
    int a=1;
    int b=2;
    swap(a, b);
	cout<< "a="<<a<<endl;
	cout<< "b="<<b<<endl;
	return 0;
}
```
The code above outputs
```
a=1
a_nickname=1
a=2
a_nickname=2
a=3
a_nickname=3
```
### Why Pointer?
```
#include <iostream>
using namespace std;
void swap(int p1, int p2) {
    int p=p1;
    p1=p2;
    p2=p;
}
int main() {
    int a=1;
    int b=2;
    swap(a, b);
	cout<< "a="<<a<<endl;
	cout<< "b="<<b<<endl;
	return 0;
}
```
The code above outputs "a=1, b=2". To accurately swap the values, using the code below:
```
#include <iostream>
using namespace std;
void swap(int &p1, int &p2) { //引用 int a=1; int b=2; int &p1=a; int &p2=b;
    int p=p1;
    p1=p2;
    p2=p;
}
int main() {
    int a=1;
    int b=2;
    swap(a, b);
	cout<< "a="<<a<<endl;
	cout<< "b="<<b<<endl;
	return 0;
}
```
