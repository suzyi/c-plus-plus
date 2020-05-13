+ vector
  + `#include <vector>`.
  + `vector<int> a(10);` defines a vector containing 10 int-type elements with all elements intilized with value 0.
  + `vector<int> a(10,1);` defines a vector containing 10 int-type elements with all elements intilized with value 1.
  + `int n = a.size()` returns the size of the vector.
+ unordered_map
  + `#include <unordered_map>`
  + `unordered_map<string, int> myMap={{"Jan", 31}, {"Feb", 28}, {"Mar", 31}, {"Apr", 30}}; cout<<myMap["Feb"]<<endl;`
  + `myMap.size()`
  + `cout << (bool)(myMap.find("Jan")!=myMap.end()) << endl;` outputs 1, indicating that the keyword "Jan" is in myMap, else outputs 0, indicating the keyword is not in myMap.
  + `cout << myMap.count("Jan") << endl;` outputs 1, indicating that the keyword "Jan" is in myMap, else outputs 0, indicating it's not in myMap.
