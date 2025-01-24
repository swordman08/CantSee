#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
#include <stdexcept>

template <class T>
class MonoStack {
public:
    MonoStack(int initialSize, char order); // Constructor with an initial size
    ~MonoStack(); // Destructor
    
    void push(T value); // Push value into the stack
    T pop(); // Pop and return the top value of the stack
    T peek() const; // Peek at the top value of the stack without removing it
    bool isEmpty() const; // Check if the stack is empty
    int size() const; // Get the current size of the stack
    void getAllElements(T* outArray) const; // Copy all elements into the provided array

private:
    T* stackArr; // Dynamically allocated array for stack elements
    int capacity; // Capacity of the stack
    int topIndex; // Index of the top of the stack (-1 if empty)
    char o; // Order of the stack ('d' for decreasing, 'i' for increasing)

    void resize(); // Resize the stack's capacity
};

template <class T>
MonoStack<T>::MonoStack(int initialSize, char order) : capacity(initialSize), topIndex(-1), o(order) {
    stackArr = new T[capacity];
}

template <class T>
MonoStack<T>::~MonoStack() {
    delete[] stackArr;
}

template <class T>
void MonoStack<T>::push(T value) {
    //Ensure there's room to push a new element, resizing if necessary
    if (topIndex >= capacity - 1) {
        resize();
    }
    if(o == 'd'){
    // For decreasing order, only push if the new value is greater than the current top value
    if (isEmpty() || (o == 'd' && peek() < value)) {
        stackArr[++topIndex] = value;
    }
    }
    if(o == 'i')
    {
    while (!isEmpty() && peek() > value) { //while value is smaller than top, and the stack is not empty. Than remove the top
            pop();
        }

    stackArr[++topIndex] = value;       //top becomes value
    
    if(isEmpty()){// Push val onto the stack
        stackArr[++topIndex] = value;
    }
    }

}
    

template <class T>
T MonoStack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return stackArr[topIndex--];
}

template <class T>
T MonoStack<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return stackArr[topIndex];
}

template <class T>
bool MonoStack<T>::isEmpty() const {
    return topIndex == -1;
}

template <class T>
int MonoStack<T>::size() const {
    return topIndex + 1;
}

template <class T>
void MonoStack<T>::getAllElements(T* outArray) const {
    for (int i = 0; i <= topIndex; ++i) {
        outArray[i] = stackArr[i];
    }
}

template <class T>
void MonoStack<T>::resize() {
    int newCapacity = capacity * 2;
    T* newArr = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
        newArr[i] = stackArr[i];
    }
    delete[] stackArr;
    stackArr = newArr;
    capacity = newCapacity;
}

#endif // MONOSTACK_H
