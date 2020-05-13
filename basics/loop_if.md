### for
```
#include <iostream>
using namespace std;
int main() {
	for(int i; i<3; i++) {
	    cout  << i <<endl;
	}
	return 0;
}
```
输出结果为：
```
0
1
2
```
### while
```
#include <iostream>
using namespace std;
int main()
{
    int i=0;
    while(i<3) {
        cout<<i<<endl;
        i++;
    }
}
```
### if
```
#include <iostream>
using namespace std;

int main() {
	int a=2;
	if(a==0) {
	    cout<<"a=1"<<endl;
	}
	else if(a==1) {
	    cout<<"a=1"<<endl;
	}
	else if(a==2) {
	    cout<<"a=2"<<endl;
	}
	else {
	    cout<<"a=3"<<endl;
	}
}
```
