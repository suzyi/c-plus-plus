+ array
  + `int a[] = {1, 2, 3, 4, 5};`
    + `cout<<*a<<endl;` gives `1`.
  + `string a[] = {"Jan", "Feb"};`
    + `cout<<a[1];` gives `Feb`.
+ vector
  + `#include <vector>`.
  + `vector<int> a(10);` defines a vector containing 10 int-type elements with all elements intilized with value 0.
  + `vector<int> a(10,1);` defines a vector containing 10 int-type elements with all elements intilized with value 1.
  + `vector<vector<string>> a = {{"ate","eat","tea"}, {"nat","tan"}, {"bat"}};`
    + `cout<<a[0][0];` gives "ate", `cout<<a[1][0];` gives "nat".
  + `int n = a.size()` returns the size of the vector.
+ unordered_map
  + `#include <unordered_map>`
  + `unordered_map<string, int> myMap={{"Jan", 31}, {"Feb", 28}, {"Mar", 31}, {"Apr", 30}};`
    + `cout<<myMap["Feb"]<<endl;` gives `28`.
  + `unordered_map<string, vector<string>> a = {{"abc", {"abc", "acb", "bac", "bca", "cab", "cba"}}, {"ef", {"ef", "fe"}}};`
    + `cout << a["abc"][3];` gives "bca".
  + `myMap.size()`
  + How do I determine if a keyword is in an unordered_map container or not?
    + Method 1- `cout << (bool)(myMap.find("Jan")!=myMap.end()) << endl;` outputs 1, indicating that the keyword "Jan" is in myMap, else outputs 0, indicating the keyword is not in myMap.
    + Method 2- `cout << myMap.count("Jan") << endl;` outputs 1, indicating that the keyword "Jan" is in myMap, else outputs 0, indicating it's not in myMap.
    + Method 3- `unordered_map<string, int> myMap;`, then for any keyword that's not in myMap, we have `myMap["anyKeyword"]=0`.
+ stack
  + `#include <stack>`
  + `stack<char> myStack;` defines a stack named myStack.
  + `myStack.push('5'); myStack.push('t'); myStack.push('b');` adds three elements to the defined stack.
  + `myStack.size()` returns the size of the stack.
  + `myStack.top()` returns the element at the top of the stack.
  + If myStack is empty, `myStack.empty()` returns 1, else returns 0.
  + `myStack.pop()` removes the top element and returns void. So `a = myStack.pop();` is a wrong line of code.
