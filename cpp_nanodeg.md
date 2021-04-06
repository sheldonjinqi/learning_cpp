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
<img src = https://user-images.githubusercontent.com/37092479/113733914-e08e9b80-96c8-11eb-8735-0f3a5133bd75.png width="600" height="400" />
