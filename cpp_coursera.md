

### C++ Classes 
* Encapsulation: encloses data and functionality into a single unit(**class**)
* Public vs. Private:
  * Private members can only used within the class
* Header file: declaration of **all** member variables and member functions.
* namespece of class,make sure add namespace for both headerfile and .cpp
```cpp
namespace uiuc {
 class Cube{
   public:
   ...
   private:
   ...
 };
}
```
### C++ Memory Model
* default is **stack** memory
* Variable has four things:
1.name 
2.type
3.value
4.location in memory
* `&` operator returns memory address of variable
* On 64-bit platforms (which describes many computers these days), these pointers may be 64 bits in size. However, some chips only make use of at most 48 bits of the data for addressing. This would be 12 digits in hexadecimal at most. The output you see with std::cout may trim any leading zeros, as well.
* stack memory is associated with the current function
* life cycle of the variable inside a function is exactly as long as the function being ran
* always starts from high addresses and grows down(newer variable smaller the address)
* stack frame is deallocated once a function is returned, but that memory space would have undefined behavior
#### pointer
* A variable that stores the memory address of the data
* adding a `*` to the type of the variable e.g(integer pointer: `int * p = &num;`)
*  use `*` to dereference a variable (remove _one level_ of indirection) e.g ` *p =42; `  
*  never return a reference to a local variable
#### heap memory
* if we ever need memory that is longer than the life cycle of a function, we have to use heap memory. 
* The only way to create and keep memory in C++ is the use of the new keyword.
*  `new` operator returns a pointer to the memory soring the data **not** an instance of the data itself
 * allocate memory on the heap
 * initialize the data structure
 * return a pointer to the start of data structure
 * only recliamed when the pointer is passed to the `delete` operator.
 * `delete` only delete the stuff on heap memory where the stack pointer is pointing to 
* e.g `int *numPtr = new int; `
* `nullptr` is a pointer that points to the memory address `0x0`. never used 
* always set  a pointer to `nullptr` once deleted
* `->` operator, to access member functions of an object stored in pointer
* `reference` variable alias another piece of memory
* pointer to array example:
```cpp
int main() {
  int *x;
  int size = 3;
  x = new int[size];

  for (int i = 0; i < size; i++) {
    x[i] = i + 3;
  }

  delete[] x;
}

```
* shouldn't use #include to literally include one cpp file in another!
*  `?:` ternary operator\
 [Boolean-valued condition] ? [expression to evaluate if true] : [expression to evaluate if false]
* outter scope value can be retrived if the inner scope value is gone.
* The address of any memory location in the stack is larger than the address of any memory location in the heap.

### Constructor
* constructor is used to create objects
* c++ compilers provides **automatic default constructor** that initialize everything to default value if no other constructor provided.
* custom default constructor, specifing default state of objects
  * member function with same name of class
  * take zero parameters
  * does not have return type
* non-default constructors that **require** arguments
* if any constructor is defined, an automatic default constructor is not defined.

### Copy Constructor
* automatic copy constructor is defined if no copy constructor is defined 
* custom copy constructor
 * a class constructor 
 * exacltly one argument, must be a const reference of the same type as the class
* invocation:
 * passed an object as parameter by value 
 * object returned from function by value 
 * initialize a new objec
 * `=` assignment operator: assignes a value to an **existing** obejct
 * custom assignment operator
  * public member function of the class
  * function name `operator=`
  * return value of a reference of the calss type 
  * exactly one argument, const reference of the class type 
