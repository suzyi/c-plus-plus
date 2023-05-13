# template
### 1-function template
With template, you can define just one swap function, but apply it to various data types. For example, 
```
// main.cpp
#include <iostream> // included to use std::cout, endl, and etc.

template<class T> // here class T can be changed to typename T
void swap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int var1 = 1, var2 = 2;
	swap(var1, var2);
	std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;

	std::string str1 = "1", str2 = "2";
	swap(str1, str2);
	std::cout << "str1=" << str1 << ", str2=" << str2 << std::endl;
	return 0;
}
```

If the returned value required (i.e., not `void functionName`), then we have be careful. To be specific, 
```
template <typename Dtype>
Dtype return_value(Dtype var_1) {
	return var_1;
}

int main() {
	float a(1.0);
	float value = return_value(a);
}
```
may fail in compilation. To solve this failure, we can use
```
int main() {
	float a(1.0);
	float value = return_value<float>(a);
}
```
### 2-class template