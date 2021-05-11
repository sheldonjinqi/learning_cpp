

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

### Tree
* each element is a **node**, each connection between nodes is an **edge**
* every node must contain one and only one root node.
* leaf nodes: no outgoing nodes 
* to be a tree: 1. must have a root 2.must have directe edges 3. must not have a cycle
* a tree is a rooted, idrected and acylclic structure 
* binary tree: every ode has **at most two** children, either left or right child 
  * height: number of edges in the **longest** path from root to leaf
  * binary tree is **full** if evey node has either zero or two children
  * is perfrect if all interior nodes have two children and leaves are at the same level
  * is complete, if the tree is perfect up until the last level and all leaf nodes are pushed to the left.
* Tree traversal(require go through every single node while search doesn't require to visit every node )
  * preorder: shout, lelft ,right
  * inorder: left, shout, right
  * post-order: left, right, shout
  * level-order: visit a level a time 
* Binary search tree 
  * Nodes in the left subtree are less than the root 
  * Nodes in the right subtree are greater than the root 
  * worst-case: go through the longest path, O(h) where h is the height of the tree. O(h) is bounded by O(n)
* Dictionary associates a **key** with **data**
  * key has to be a unique identifier
  * ADT: find, insert (adds a key/data pair), remove(removes a key) , emptuy(check if dict is empty 
  * When remove a node, need to consider the number of children the node have 
  * In-order predecessor: the previous node in an in-order traversal of a BST(right most node of the left subtree)
  * n! ways to insert n number of variables to form a bst tree
    * always the right-mode node in the node's left sub-tree  
  ![image](https://user-images.githubusercontent.com/37092479/116792953-cf4f6980-aa91-11eb-9614-8c671ec68b2d.png)
  * height balance factor is the difference in height between left and right subtreas (right minus left)
  * Balanced BST, every node's balance factor has a mgnitude of **0 or 1** (-1,0,1)
  * number of nullptr for a binary tree is # of node +1 (for every new node, there is a net increase of one pointer to nullptr)
  * BST rotation, transforms a stick into a mountain by raising the middle node 
  * always transform an elbow to a stick
  * 4 possible BST rotations: L, R, LR, RL, run in O(1) time
* AVL Tress:
  * store the height of every node as part of the node to  compute balance factor quickly 
  * insert: 1.insert at proper place 2. check for imbalace 3. rotate, if necessary 4. update height 
  * Every node in an AVL tree has a height balance factor of -1, 0 or 1
* B-Tree
  * O() time assumes uniform access time to single data. 
  * create a data structure to perform well both on memory and disk
  * a node can have several keys 
  * order is maximum number keys a node can have + 1 
  * each internal node can have at most **m** children
  * all keys within a node are in sorted order
  * a root node can be a leaf or have **[2,m]** children
  * each non-root,internal node has **[ceil(m/2),m]** children
  * all leaves are on same level
  * height of the BTree determines maximum number of seeks 
  * height of the structure is logm(n)
  * number of seeks is no more than logm(n)
### Heap 
* every child node is larger than the parent
* A **complete** binary tree T is min-heap if 
  * T={}
  * T={r,T_l,T_r} where **r** is less than the roots of {T_l,T_r} and {T_l,T_r} are min-heaps
  * for min heap, parent = i/2, child(left) = i*2, child(right) = i*2+1/
* Insert 
  * check if children is larger than parent 
* Remove
  * Always remove the minimum value, root of the tree
  * swap the root with the last element, swap with smallert child  
* build heap in O(n)
  *  Create a complete tree of the items in any order, then call heapifyDown on every non-leaf node from the bottom of the tree up to the root
* heap sort: n x lg(n)
  * build heap O(n)
  * n x remove O(lg(n))
  * Swap elements to order  

# Unordered data structure
* A hash table consists of three things： 
  * Hash Function
  * An Array 
  * Collision Handling Strategy（multiple keys to one value）
* Hash function
  * transfers an input into a number 
  * onto function: That every single element in the array is full, and we can map every single element into our data onto that array
  * consists of: 
  * 1. hash(transform input into int) 
  * 2. compression %N
  * requirement for Hash
  * computation time: constant runtime O(1)
  * deterministic:
  * satisfy the SUHA(simple uniform hashing assumption): uniform distribution of hashing random key through entire key space.
* collision handling 
  * separate chainin with linked list : insert the collision at the begining of linked list 
  * load factor: n/N(#elements in table / size of table)
  * probe-based hashing: find an empty space in array
  * double hashing(prevent primary clustering): use a second hash function to handle cllision 
  * separate chains is better for big record 
  * double hashing has higher structure speed 
  * hash table replaces dictionary 
  * hash table can't do nearest neighbor 
* std::unordered_map is the hash table.
*  [] can only be used on non-const instances of a map
*  at function will search for a given key and return a reference like [], but at will throw an exception if the key is not found, instead of modifying the map.
*  find function, which actually returns an iterator type, which is like a special pointer. The iterator points to a key-value
pair found, or otherwise to the map’s end iterator given by end().
### Disjoint Sets
* disjoint set is a collection of sets  and each set has a representative member
* elements in the set are equivalent 
* **find** operation returns the identity element of the set that contains the number that are looking for
* identity element has to be unique and usually is the first element of the set 
* uptree improves the update speed when union sets but not the ideal case, but find operation could be slow when its one long linked tree. desire: short and flat tree 
* smart union use -h-1 as value for the root node instead of -1. 
* union by height, put the shorter tree to the higher tree. keep the height of the tree as small as possible. no change to the total height, but changed the height of the nodes in shorter tree
* union by size, minimize the number of nodes that increase in height 
* both by height or by size, guaruantee the height of the tree is log(n)
* path compression, point every node that went through to the root node.
* iterated log: number of times you can take a log of a number. log*(n)=0 if n<=1 and 1+log*8(log(n)) when n >1 . 
* m find and union operations result in the worst case running time of O(m*lg*(n)),O(1)*
### Graphs


