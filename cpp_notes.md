---
# Modulo 1 Intro to C++
* Compiler language: Have a machine check your code, catches the error ealie \
* Dynamically Scripted Language: Run quickly, do trial & error \
* Every C++ program has a main function  \
* `>>` stream insertion operator, writes the right side to the left side
* `std::ifstream` can be used to handle input file streams.
  - `std::ifstream my_file;` initialize the object `my_file` which can be used as boolean object to check if it was initialized successfully.
* `std::istringstrem` can be used to process strings. 
  - The extraction operator `>>` writes the stream to the variable on the right of the operator and returns the `istringstream` object 
  - `istringstream` can be used as boolean, e.g.(`my_stream >> n`)
* `enum`: defines a custom type with values restricted to a fixed range. e.g(```C++ enum class Color {white, black, blue, red};```)
