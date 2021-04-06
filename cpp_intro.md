# Basics 

* Each C++ program consists of two parts: the preprocessor directives and the main function
  - Preprocessor starts with `#`
* `const`: Value does not change for the life of the program.
* File IO
  - `ofstream`(for writing): always have the flag `ios:out` enabled, plug any specified flag 
  - `ifstream`(for reading): similar to `ofstream`
  -  `fstream`(both reading and writing) default flag `ios::int` and `ios::int`, but would be overriden by specified flag.
* Header Files: information about how to do a task. Anything that is not used in the main program. use `" .hpp"` since the header file is in the local directory.
* `std::cin`: Does not read strings with space in it. It consider a space as the end of the input.
  - can read numbers directly 
  -use `std::geline` instead (read character )
  - `stringstream` from `sstream` library convert a string to other type (e.g `std::stringstream(stringWidth) >> width;`)

### Arithmetic Operations 
* Implicit conversion between types: can't assign float to char but can do the other way around. 
* Prefix operators: 1. increment the value; 2. return a reference 
* Postfix operators: 1.create a **copy** of the variable 2. increment the value 3. return the copied value from **BEFORE** increment

### Control flow
* Switch statement: 
  * matching case would be executed. 
  * without `break`, switch statement would keep executing the cases come after it even the case doesn't match, but **not** the **default** case. 
* infinite loop: 
```cpp
for( ; ;)
{
     std::cout<<"This for loop will run forever\n";
}
```
### Pointers 
* When declare a variable `type * variable_name` means the variable is a pointer, the address of the variable is given by `&a`
* use `*` to dereference the pointer, retriving the value stored at the address.

##Array
* declaration:\
`variableType arrayName [ ] = {variables to be stored in the array};`\
`variableType arrayName[array size]`
