# inline
```
inline int sum(int x, int y) {
    return x + y;
}

int main() {
    int a=10;
    int b=10;
    int result = sum(a, b);
}
```
`Inline` means inserting a piece of code to current position to improve efficiency, not calling it. By using inline function, we can reduce call cost of a function, especially when it loops thousand of times. For example, caffe (a deep learning framework) can use `inline float sigmoid(float) { return 0.5 * tanh(0.5 * x) + 0.5; }` to reduce running time over thousand of scalars of many blobs.

But we have to be remember that:
+ it is just a suggestion not a requirement, which means the compiler may not treat it as an inline function.
+ the compiler will not treat it as an inline function in recursive situation.
+ the compiler will not treat it as an inline function if there are too many lines inside it.

A question comes out - now that `inline` can improve efficiency, why don't we use in all situations? A situation is 
```
inline int sum(int x, int y) {
    int a=10;
    int b=10;
    return x + y;
}

int main() {
    int a=10;
    int b=10;
    int result = sum(a, b);
}
```
which leads a conflict.