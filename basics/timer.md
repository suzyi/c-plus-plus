### timer
```
time_t begin=std::time(0); // get current time
int repeat_times=500;
for (int i=0; i<repeat_times; i++) {
   // run a piece of code here.
}
time_t end=std::time(0);
std::cout << "Avg time consumption: " << (end-begin)*1000.0/repeat_times << " ms" << std::endl;
```