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
### class
```
#include <iostream>
using namespace std;

class student {
    public:
    string name;
    void set_info(string Name, int Math, int English) {
        name = Name;
        math = Math;
        english = English;
    }
    void print() {
        cout<<name<<": Math="<<math<<", English="<<english<<endl;
    }
    private:
    int math, english;
};
int main() {
    student Jorge;
    Jorge.set_info("Jorge", 89, 91);
    Jorge.print();
    cout<<Jorge.name<<endl;
    // cout<<Jorge.math<<endl;
	return 0;
}
```
