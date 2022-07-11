### timer
```
#include <ctime>
time_t begin=std::time(0); // get current time
int repeat_times=500;
for (int i=0; i<repeat_times; i++) {
   // run a piece of code here.
}
time_t end=std::time(0);
std::cout << "Avg time consumption: " << (end-begin)*1000.0/repeat_times << " ms" << std::endl;
```

```
#include <chrono>

std::chrono::duration<double, std::milli> duration(0);
for (size_t i=1; i<img_vec.size(); i++) {
   auto start = std::chrono::high_resolution_clock::now();
   infer(img_vec[i]);
   auto end = std::chrono::high_resolution_clock::now();
   duration += (end - start);
}
std::cout << "avg inference time: " << duration.count() / img_vec.size() << " ms" << std::endl;
```
