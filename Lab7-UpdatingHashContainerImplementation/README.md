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