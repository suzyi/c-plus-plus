### print hello world
In our computer, create an empty folder named "print_hello_world" and then download files from [here](https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library). Make sure it has the following structure:
```
print_hello_world
├── CMakeLists.txt
├── include
│   └── static
│       └── Hello.h
└── src
    ├── Hello.cpp
    └── main.cpp
```

Then open a terminal and run
```
print_hello_world> mkdir build
print_hello_world> cd build
print_hello_world\build> cmake -DCMAKE_BUILD_TYPE=Release "Visual Studio 12 2013 Win64" ..
```
