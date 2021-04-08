`&` works in 3 scenarios -- acquire address, reference, and logical "and".
+ acquire address: `int a=10; int *b=&a;`
+ reference: `int a=1; int &a_nickname=a;`
+ logical "and": `A = 60; B = 13;` then `A`, `B` can be represented as `A = 0011 1100; B = 0000 1101;` which leads to `A & B = 0000 1100;`
  + as an application, logical "and" can be used to judge if a number is odd or even by `if(A & 1==1) cout<<"A is odd";`

#### when do I use a dot or arrow?
`.` vs `->`: Here is a hot [discussion](https://stackoverflow.com/questions/4984600/when-do-i-use-a-dot-arrow-or-double-colon-to-refer-to-members-of-a-class-in-c) on stackoverflow.
+ `a.b` is only used if `b` is a member of the object (or reference to an object) `a`.
  + `Listnode head(-1);` then `head.next`.
+ `a->b` is only used if `a` is a pointer. It is a shorthand for `(*a).b`, the `b` member of the object that `a` points to.
  + `Listnode *slow = &head;` then `slow->next;`

Cases such as `Network& network` and `torch::optim::Optimizer& optimizer` often appear as inputs of a function, for instance,
```
template <typename DataLoader>
void train(
    Network& network,
    DataLoader& loader,
    torch::optim::Optimizer& optimizer,
    size_t epoch,
    size_t data_size) {
  size_t index = 0;
  network->train();
  float Loss = 0, Acc = 0;

  for (auto& batch : loader) {
    auto data = batch.data.to(options.device);
    auto targets = batch.target.to(options.device).view({-1});

    auto output = network->forward(data);
    auto loss = torch::nll_loss(output, targets);
    assert(!std::isnan(loss.template item<float>()));
    auto acc = output.argmax(1).eq(targets).sum();

    optimizer.zero_grad();
    loss.backward();
    optimizer.step();

    Loss += loss.template item<float>();
    Acc += acc.template item<float>();

    if (index++ % options.log_interval == 0) {
      auto end = std::min(data_size, (index + 1) * options.train_batch_size);

      std::cout << "Train Epoch: " << epoch << " " << end << "/" << data_size
                << "\tLoss: " << Loss / end << "\tAcc: " << Acc / end
                << std::endl;
    }
  }
}
```
where such variables act as objects.

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
