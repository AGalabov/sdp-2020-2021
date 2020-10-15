#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <iostream>

template <class T>
class LinkedList
{
private:
    struct box
    {
        T data;
        box *next;
        box(const T &data, box *next = nullptr) : data(data), next(next)
        { /* */
        }
    };
    box *first;

public:
    LinkedList();
    ~LinkedList();

    void pushFront(const T &val);
    void pushBack(const T &val);
	  void print() const;
    size_t size() const;
    bool contains(const T &val) const;
};
//#include "LinkedList.cpp"

template <class T>
LinkedList<T>::LinkedList() : first(nullptr)
{ /**/
}

template <class T>
LinkedList<T>::~LinkedList()
{
    box *crr = this->first;

    while (crr != nullptr)
    {
        box *save = crr;
        crr = crr->next;
        delete save;
    }

    this->first = nullptr;
}

// newBox(val, *first) -> (1, *2) -> (2, *3) -> (3, null)

//* void pushFront(const T& val) - добавя елемент със стойност val в началото на списъка
template <class T>
void LinkedList<T>::pushFront(const T &val)
{
    box *newBox = new box(val, this->first);
    this->first = newBox;
}

// (1, *2) -> (2, *3) -> (3, null) -> nullptr
// (1, *2) -> (2, *3) -> (3, newBox*) -> newBox(val, null)

//* void pushBack(const T& val) - добавя елемент със стойност val в края на списъка
template <class T>
void LinkedList<T>::pushBack(const T &val)
{
    box *newBox = new box(val);
    if (this->first == nullptr)
    {
        this->first = newBox;
        return;
    }

    box *p = this->first;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->next = newBox;
}

template<class T>
void LinkedList<T>::print() const
{
    box* crr = this->first;
    while(crr != nullptr)
    {
		std::cout << crr->data << " -> ";
		crr = crr->next;
	}
    std::cout << '\n';
}

template<class T>
size_t LinkedList<T>::size() const
{
    size_t count = 0;
    box *crr = first;
    while(crr != nullptr)
    {
        crr = crr->next;
        ++count;
    }
    return count;
}
template<class T>
bool LinkedList<T>::contains(const T &val) const
{
    box* crr=first;
    while(crr!= nullptr)
    {
        if(crr->data == val)
        { 
            return true;
        }
        
        crr=crr->next;
    }
    return false;
}


#endif