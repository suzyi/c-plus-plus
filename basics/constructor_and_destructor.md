### 1 - constructor
#### Why do we need a constructor?
A constructor is used to complete the initialization process when an object is created.
### How to define a constructor?
+ The consturctor of a classs has the same name as the class itself. For example, 
```
class Counter
{
public:
    Counter()
    {
        m_value = 0;
    }

private:
  int m_value;
}
```

### 2 - destructor
