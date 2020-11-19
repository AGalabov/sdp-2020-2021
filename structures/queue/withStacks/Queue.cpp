template<class T>
void Queue<T>::push_back(const T& x)
{
    pushStack.push(x);
}

template<class T>
void Queue<T>::pop_front()
{
    if(size() == 0) return;

    if(popStack.empty())
    {
        while(!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }

    popStack.pop();
}

template<class T>
void Queue<T>::print_front()
{
    if(size() == 0) return;

    if(popStack.empty())
    {
        while(!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }

    std::cout << popStack.top() << " ";
} 

template<class T>
T Queue<T>::front()
{
    if(size() == 0) throw "Empty queue!\n";

    if(popStack.empty())
    {
        while(!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }

    return popStack.top();
}

template<class T>
T Queue<T>::back()
{
    if(size() == 0) throw "Empty queue!\n";

    if(pushStack.empty())
    {
        while(!popStack.empty())
        {
            pushStack.push(popStack.top());
            popStack.pop();
        }
    }
    
    return pushStack.top();    
}

template<class T>
bool Queue<T>::empty() const
{
    return size() == 0;
}

template<class T>
size_t Queue<T>::size() const
{
    return pushStack.size() + popStack.size();
}

