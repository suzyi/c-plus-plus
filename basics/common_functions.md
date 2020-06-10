### sort
+ `#include <algorithm>`
+ `string a = "tea"; sort(a.begin(), a[3]); cout<<a<<endl;` gives `aet`.
### accumulate
```
#include <iostream>
using namespace std;
#include <numeric>
#include <vector>
int main() {
	int a[] = {1, 4, 2, 5};
	int len = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<len; i++) cout << a[i] <<" ,";
	cout<< "The summation of a is "<< accumulate(a, a+4, 0)<<endl;
	vector<int> vec(a, a+len);
	for(int i=0; i<len; i++) cout << vec[i] <<" ,";
	cout<< "The summation of the first 3 elements of vec is "<< accumulate(vec.begin(), vec.begin()+3, 0)<<endl;
	return 0;
}
```
gives 
```
1 ,4 ,2 ,5 ,The summation of a is 12
1 ,4 ,2 ,5 ,The summation of the first 3 elements of vec is 7
```
### >>
```
int a = 6>>1; // 6的二进制是110，去掉末尾得到11，结果a=3
int b = 5>>1; // 5的二进制是101，去掉末尾得到10，结果b=2
```
