

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
### variable storage
* by default stored directly in memory
* storage by pointer
* storage by reference (takes zero-bit of memory)
 * must be assigned when variable is initialized
* never return a reference to a stack variable created on stack of current function.
### Destructor
* destructor should **never** be called directly, called by system.
* function name: name of class preceded by tilde ·~·
* zero arguments and no return
* custom destructor is essential when an object allocates an external resource that must be closed , e.g( heap memory, open files, shared memory
* don't try to derefence a uninitialized variable. 
* Plain built-in types, such as int, that are not initialized will have unknown values.
# modern range-based for loop 
`for ( temporary variable declaration : container ) { loop body }`
* if you declare an ordinary temporary variable in the loop, it just gets a copy of the current loop item by value.
* template type: can take on different types , e.g(std::vector) 
 * initialize: std::vector<Typename> variablename
 * `::push_back(T); add to back of array;
 * `::operator[]` to access specific elemnt
 * v.size returns the size 
 * ostream friend function allows to print out the object **double check** `friend std::ostream& operator<<(std::ostream & os, const Game & game);`
 * `this` pointer is only valid in member functions.

## Ordered Data Structures
### Array 
* stores data in blocks of **sequential** memory, index starts at 0.
* All data in an array must be of the **same** type
* have a fixed capacity, has a maximum number of elements 
* need to create a larger array and copy it over, when new element needs to be added to a full array.
* **std::vector** grows in size automatically, usually double the size 
### Linked memory
* stores a data together with a pointer to the location in memory of next list node
* A list node refers to pair of both data and the link(pointer)
*  LIstNode elements linked together form a linked list
* head pointer stores the link to the begining of the list 
* runtime grows based on the size of the list when trying to access a given index
* capacity is bounded only by the memory available on the system, not fixed.
* must contain the same type of instance
* pointer to nullptr marks the end of the list
### Runtime analysis
* big O stands for how time complexity increases with the size of input
* average work per element: amertized run time(some operations take longer, expanding the array here.) O(n)/n = O(1)*.
* Amortized analysis doesn't naively multiply the number of invocations with the worst case for one invocation. e.g. resizing an array, sometimes need to create a new array and coply over.
### Array and List opearations
* Finding a value
 * binary search for sorted array is O(lg(n))
 * for unsorted array O(n)
 * all list O(n) 
* Insert After & Delete After
  * O(n) for array
  * O(1) for linked list
### Queue
* First-in first out  
* **Abstract Data Type** is how data interacts with the structure.
  * create _ create empty queue
  * push -> adds data to he back
  * pop -> remove from front
  * empty -> returns true if queue is empty
* included in std::queuev 
* can be implemented by both array or linked list with all four above operations in O(1)
### Stack
* last-in first-out
* adt is same as queue

