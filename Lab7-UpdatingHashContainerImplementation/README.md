# Lab 7: Updating Hash Container Implementation

## Description
Use the implementation of **hashmap.h** and **testHashmap.cpp** that we studied and do the 
following modifications:
- modify the implementation of `insert()` so that it provides "safe insert", i.e.: returns a 
pair: `<pointer, result>`, where
    - `pointer` is a pointer to the newly inserted value or the old value with the same 
key 
    - `result` is a boolean value which is true if the element is inserted
- on the basis of your updated `insert()` implementation, modify the implementation of 
the overloaded indexing operator [] to eliminate inefficient second invocation of 
`find()`. That is, in your implementation, `find()` should only be invoked once. 
- modify the implementation of `erase()` so that it returns a pair `<pointer, result>`, where
    - `pointer` is a pointer to the element past one erased. Note that if the next 
element in a different bucket, it should still be returned. In case the element with 
the key specified to `erase()` does not exist, the value of the returned pointer is 
unspecified. If `erase()` removes the last element of the container (the last 
element of the list of the last bucket), then `erase()` should return `nullptr`.
    - `result` is a boolean value which is `true` if the element is successfully erased; 
`result` is `false` if the element with the specified key is not present in the 
container.
- implement void `rehash(size_t n)` sets the size the number of buckets in the 
container to `n`. Note that the existing elements need to be re-arranged according to their 
new hash value. Note also that `Hash:` the object that provides hashing, needs to be 
updated to contain the new number of buckets. If the parameter n is smaller than the 
current number of buckets, no actions need to be taken.

Provide test code that declares and populates a container and then demonstrates the operation of 
the functions you implemented.

## Credits
Work Completed by Nicholas Miller

## Usage
- **make** builds the program using `clang++ -std=c++11 testHashmap.cpp -o testHashmap`
- **make run** runs the program with `./testHashmap`
- **make clean** removes the executable from the directory