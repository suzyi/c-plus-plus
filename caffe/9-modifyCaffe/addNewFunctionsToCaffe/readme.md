# caffeCpuMse

Add a new function, called caffe_cpu_mse, to caffe.

### 1 - modify header file
Insert code below to the file "caffe/include/caffe/util/math_functions.hpp".
```
float caffe_cpu_mse(const int count, const int num, const float* a, const float* b);
```
### 2 - modify source file
Insert code below to the file "caffe/src/caffe/util/math_functions.cpp"
```
float caffe_cpu_mse(const int count, const int num, const float* a, const float* b) {
	float y(.0001);
	caffe_sub(count, a, b, &y);
	float dot = caffe_cpu_dot(count, &y, &y);
	float value = dot / num /float(2);
	return value;
}
```
### 3 - calculate mse via caffe_cpu_mse
Open a terminal and execute `F:\cpp\caffe\10-caffeCpuMse> bash run_me.sh`

### 4 - errors you may encounter
+ Error 1: "caffe_cpu_mse is not a member of caffe" may appear. 
    + Solution: This is possilbly because you have two caffes installed on your PC. Check that via `message("caffe found at path: ${Caffe_DIR}.")` in CMakeLists.txt.