#ifndef Q_INCLUDED
#define Q_INCLUDED
#include <iostream>
#include <stack>
#include <exception>


template<class T>
class Queue
{
private:
    std::stack<T> pushStack{}, popStack{};

public:
    void push_back(const T& x);
    void pop_front();
    void print_front();

    T front();
    T back();

    bool empty() const;
    size_t size() const;
};
#endif

#include "Queue.cpp"