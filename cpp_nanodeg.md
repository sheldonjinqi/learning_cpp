---
# Foundations
### Intro to C++
* Compiler language: Have a machine check your code, catches the error ealie \
* Dynamically Scripted Language: Run quickly, do trial & error \
* Every C++ program has a main function  \
* `>>` stream insertion operator, writes the right side to the left side
* `std::ifstream` can be used to handle input file streams with `<fstream>` library
  - `std::ifstream my_file;` initialize the object `my_file` which can be used as boolean object to check if it was initialized successfully.
* `std::istringstrem` can be used to process strings. 
  - The extraction operator `>>` writes the stream to the variable on the right of the operator and returns the `istringstream` object 
  - `istringstream` can be used as boolean, e.g.(`my_stream >> n`)
* `enum`: defines a custom type with values restricted to a fixed range. e.g( enum class Color {white, black, blue, red}; )

### A* Search
<img src = https://user-images.githubusercontent.com/37092479/113733914-e08e9b80-96c8-11eb-8735-0f3a5133bd75.png width="300" height="200" />\ 
<img src = https://user-images.githubusercontent.com/37092479/114233129-e5628200-994a-11eb-92f5-ce88e4518ff6.png width="400"/>\
### test
* pass by value vs pass by reference: the former doesn't change the value, the later does 
* `const`, variable is evaluated at run time but can't be modified.
* `constexpr`, variable evaluated at **compile** time.
*  Example of a range-based loop through 2d array `const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};`:
```cpp
   for(const int (&row) [2] : delta){
   .......
   }
 ```
 * Arrays are a lower level data structure than vectors, and can be slightly more efficient, in terms of memory and element access.
 * Array is **fixed** length
### Multifile programs 
* use of header file makes **order** of function declaration **not matter** compared to a single file. 
* The function declarations in the header file **don't need** variable names but its ok to have variable names, just variable types
* Make sure the header is included only once using following or `pragma once`:
```cpp
#ifndef HEADER_EXAMPLE_H
#define HEADER_EXAMPLE_H
```
* include other header files in `.cpp` not `.h`
* Each file is compiled alone and must have all the declarations and libraries necessary to compile, so the necessary libraries must be included.

### CMake &make
1. First thing is to specifie the minimum version of cmake and C++ required.
2. Project name 
3. add executable
4. add build directory
* using `Cmake` and `make`, we can only run `Make` after change some files.
Example:
```cpp
cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 14)
project(learning_cpp)
add_executable(test_example src/main.cpp src/vect_add_one.cpp src/increment_and_sum.cpp)
```

### Reference 
* def: a reference is another name given to an existing variable. On the left hand side of any variable declaration, the & operator can be used to declare a reference
*  reference cannot be made to another object.
### Pointer
* def: a variable that stores the memory address of an object in your program.
* `*` dereference the variable when its not at left side
* scope is key to pointer.

<img src = https://user-images.githubusercontent.com/37092479/114255120-5ae94500-9981-11eb-85ca-934b8600c33f.png width="600"/>\

### Map/ Hash table
* a data structure that uses **key/value** pairs to store data, and provides efficient lookup and insertion of the data
* `.find` returns a `iterator`, which is a pointer that points to the beginning of the hash table; if not match, returns `mapname::end()`.

### OOP
* `constructor` allows to instantiate new objects with the desired data/
* inheritance: use public methods and attributes from another class. e.g
```cpp
class Sedan : public Car {
    // Sedan class declarations/definitions here.
};
```
* When the class methods are defined outside the class, the scope resolution operator :: must be used to indicate which class the method belongs to.
* can use _initializer list_ for constructor. e.g `Car(string c, int n) : color(c), number(n) {}`. empty constructor body
