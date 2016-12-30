# Chain-Varient-of-Stack
A node-only stack that doesn't use a wrapper/container object.

Simple stack that uses a single node as the parent which always acts as the top object in the stack.

When an object is `popped` from the stack, the second to last object added to the stack is deleted and the parent node object takes it's place as the top item in the stack again. This same procedure takes place when an object is `pushed` onto the stack: A new node is added as the second-to-last object in the stack and the parent node takes it's place as the top node in the stack.

That said this still functions as a normal LIFO stack.

```C++
template<typename T>
class chain {
  public:
    //Constructs the chain with a single object.
    chain(const T& object);
    //Constructs the chain with no objects.
    chain();
    //Destroys the chain and all previously attached links.
    //NOTE: When a single link is destroyed via pop() the link's attached previous node is NULL'd to avoid accidental freeing.
    ~chain();
    
    //Adds a new object to the end of the chain.
    void push(const T& object);
    // Removes the last object in the chain and returns it's value.
    const T pop();
    // Gets the last object in the chain.
    const T& top();
    
    //Get the length of the chain.
    int size();
    //Swap the chain links between two chains.
    void swap(chain<T>& link);
}
```
