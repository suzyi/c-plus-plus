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

Define a struct by inheritation
```
// This sample code is from https://github.com/pytorch/examples/blob/master/cpp/mnist/mnist.cpp
struct Net : torch::nn::Module {
    
    //constructor
  Net()
      : conv1(torch::nn::Conv2dOptions(1, 10, /*kernel_size=*/5)),
        conv2(torch::nn::Conv2dOptions(10, 20, /*kernel_size=*/5)),
        fc1(320, 50),
        fc2(50, 10) {
    register_module("conv1", conv1);
    register_module("conv2", conv2);
    register_module("conv2_drop", conv2_drop);
    register_module("fc1", fc1);
    register_module("fc2", fc2);
  }

  torch::Tensor forward(torch::Tensor x) {
    x = torch::relu(torch::max_pool2d(conv1->forward(x), 2));
    x = torch::relu(
        torch::max_pool2d(conv2_drop->forward(conv2->forward(x)), 2));
    x = x.view({-1, 320});
    x = torch::relu(fc1->forward(x));
    x = torch::dropout(x, /*p=*/0.5, /*training=*/is_training());
    x = fc2->forward(x);
    return torch::log_softmax(x, /*dim=*/1);
  }

  torch::nn::Conv2d conv1;
  torch::nn::Conv2d conv2;
  torch::nn::Dropout2d conv2_drop;
  torch::nn::Linear fc1;
  torch::nn::Linear fc2;
};
```
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
