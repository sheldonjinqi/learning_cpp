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
