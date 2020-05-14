### struct
```
#include <iostream>
using namespace std;

struct student {
    string name;
    int age;
    int Math;
    int English;
    int add() {
        return Math+English;
    }
};
int main() {
    student Jorge;
    Jorge.name = "Jorge";
    Jorge.age=19;
    Jorge.Math = 89;
    Jorge.English = 91;
	cout  << Jorge.name <<"'s total grade is "<<Jorge.add()<<endl;
	return 0;
}
```
The code above outputs "Jorge's total grade is 180".
