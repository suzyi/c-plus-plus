+ array
  + `int a[] = {1, 2, 3, 4, 5};`
    + `cout<<*a;` gives 1.
    + `cout<<sizeof(a)/<<sizeof(a[0]);` give 5.
  + `string a[] = {"Jan", "Feb"};`
    + `cout<<a[1];` gives "Feb".
    + `string s = "data/25.png", token = s.substr(0, s.find("/"))` gives "token = data".
+ bitset
  + `#include <bitset>`
  + `bitset<5> a;`
    + `cout << "a=" << a << endl;` gives a=00000
  + `bitset<5> b(3);`
    + `cout << "b=" << b << ", " << b.size() << ", "<<  b[0] << ", "<<  b[1] << ", "<<  b[2] << endl;` gives b=00011, 5, 1, 1, 0
+ deque
  + `#include <deque>`
  + `deque<Point> snake; snake.emplace_back(point_1);`
    + `snake.front()`
    + `snake.pop_front();`
+ [pair](http://www.cplusplus.com/reference/utility/pair/pair/)
```
// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main () {
  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
  return 0;
}
```
+ queue
  + `#include <queue>`
  + `queue<int> q; for(int i=0; i<5; i++) q.push(i);`
    + `cout << q.size();` gives 5.
    + `cout << q.front() << ", " << q.back();` gives "0, 4".
    + `q.pop(); cout << q.front();` gives 1.
+ stack
  + `#include <stack>`
  + `stack<char> myStack;` defines a stack named myStack.
  + `myStack.push('5'); myStack.push('t'); myStack.push('b');` adds three elements to the defined stack.
  + `myStack.size()` returns the size of the stack.
  + `myStack.top()` returns the element at the top of the stack.
  + If myStack is empty, `myStack.empty()` returns 1, else returns 0.
  + `myStack.pop()` removes the top element and returns void. So `a = myStack.pop();` is a wrong line of code.
+ unordered_map
  + `#include <unordered_map>`
  + `unordered_map<string, int> myMap={{"Jan", 31}, {"Feb", 28}, {"Mar", 31}, {"Apr", 30}};`
    + `cout<<myMap["Feb"];` gives 28.
    + 
      ```
          for(auto tmp:myMap) {
            cout<<tmp.first<<": "<<tmp.second<<endl;
          }
      ```
    + `myMap["May"] = 31; cout<<myMap["May"];` gives 31.
  + `unordered_map<string, vector<string>> a = {{"abc", {"abc", "acb", "bac", "bca", "cab", "cba"}}, {"ef", {"ef", "fe"}}};`
    + `cout << a["abc"][3];` gives "bca".
  + `myMap.size()`
  + How do I determine if a keyword is in an unordered_map container or not?
    + Method 1- `cout << (bool)(myMap.find("Jan")!=myMap.end()) << endl;` outputs 1, indicating that the keyword "Jan" is in myMap, else outputs 0, indicating the keyword is not in myMap.
    + Method 2- `cout << myMap.count("Jan") << endl;` outputs 1, indicating that the keyword "Jan" is in myMap, else outputs 0, indicating it's not in myMap.
    + Method 3- `unordered_map<string, int> myMap;`, then for any keyword that's not in myMap, we have `myMap["anyKeyword"]=0`.
+ vector
  + `#include <vector>`.
  + `vector<int> a(10);` defines a vector containing 10 int-type elements with all elements intilized with value 0.
  + `vector<int> a(10,1);` defines a vector containing 10 int-type elements with all elements intilized with value 1.
  + `int a[] = {1, 4, 2, 5}; int len = sizeof(a)/sizeof(a[0]); vector<int> vec(a, a+len);`
  + `vector<vector<string>> a = {{"ate","eat","tea"}, {"nat","tan"}, {"bat"}};`
    + `cout<<a[0][0];` gives "ate", `cout<<a[1][0];` gives "nat".
    + `a.push_back({"ef", "fe"}); cout<<a[3][1];` outputs "fe".
  + `int n = a.size()` returns the size of the vector.
  + `vector<string> a = {"Mo", "Tu", "We", "Th", "Fr"};`
    + `cout << a.back() << ", " << a[a.size()-2];` gives "Fr, Th".
    + `a.insert(a.begin(), "Su")`. then a = {"Su", "Mo", "Tu", "We", "Th", "Fr"};
