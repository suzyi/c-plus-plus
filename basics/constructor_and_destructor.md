### 1 - constructor
#### Why do we need a constructor?
A constructor is used to complete the initialization process when an object is created.
### How to define a constructor?
+ The consturctor of a classs has the same name as the class itself. For example, 
```
// https://docs.microsoft.com/zh-cn/cpp/cpp/constructors-cpp?view=msvc-160
class Box {
public:
    // Default constructor
    Box() {}

    // Initialize a Box with equal dimensions (i.e. a cube)
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // member init list
    {}

    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}

    int Volume() { return m_width * m_length * m_height; }

private:
    // Will have value of 0 when default constructor is called.
    // If we didn't zero-init here, default constructor would
    // leave them uninitialized with garbage values.
    int m_width{ 0 };
    int m_length{ 0 };
    int m_height{ 0 };
};
```

### 2 - destructor
Different from Constructor, a class can have only one destructor which clean the object. If no any destructor given, compiler will automatically add one.
```
class Box {
public:
    // Default constructor
    Box() {};
    
    // Destructor
    ~Box();
};
```