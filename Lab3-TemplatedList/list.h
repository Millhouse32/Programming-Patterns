// node class tempate used to contruct lists 
// Wayne Cheng 
// 2/01/18 

#ifndef LIST_H_ 
#define LIST_H_ 

// the pointer part of every list is the same 
// lists differ by data part 
template <typename T> 
class node
{ 
	public: 
	node(): next_(nullptr) {} 
	
	// functions can be inlined 
	T getData()const
	{
		return data_;
	} 
	
	void setData(const T& data)
	{
		data_=data;
	} 

	// or can be defined outside 
	node* getNext() const; 
	void setNext(node *const); 

	private: 
	T data_; 
	node *next_; 
}; 

// 
// member functions for node 
// 
template <typename T>
node* node::getNext()const
{ 
	return next_; 
} 

template <typename T>
void node::setNext(node *const next)
{ 
	next_=next; 
} 

#endif // LIST_H_ 