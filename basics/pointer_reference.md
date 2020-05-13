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
void swap(int &p1, int &p2) {
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
void swap(int &p1, int &p2) {
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
