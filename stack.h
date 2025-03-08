#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
class Stack: private std::vector<T>{
public:
    Stack(){}
    ~Stack(){}
    bool empty() const{
        return std::vector<T>::empty();
    }

    size_t size() const{
        return std::vector<T>::size();
    }

    void push(const T& item){
        std::vector<T>::push_back(item);
    }

    void pop(){
        if(empty()){
            throw std::underflow_error("Empty");
        }

        std::vector<T>::pop_back();
    }

    const T& top() const{
        if(empty()){
            throw std::underflow_error("Empty");
        }

        return std::vector<T>::back();
    }
};

#endif