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

```
template <typename Dtype>
inline Dtype sigmoid(Dtype x) {
  return 0.5 * tanh(0.5 * x) + 0.5;
}
```
### 2-class template