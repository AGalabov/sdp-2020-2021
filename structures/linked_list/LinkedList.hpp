#ifndef _LINKED_LIST
#define _LINKED_LIST//

#include <iostream>
#include<stdexcept>

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
    box *first, *last;
    size_t numberOfElements;
    void copy(const LinkedList<T> &list);
    void clear();

public:
    LinkedList();
    LinkedList(std::initializer_list<T>);
    ~LinkedList();
    LinkedList(const LinkedList<T> &);
    LinkedList &operator=(const LinkedList<T> &);
    void pushFront(const T &val);
    void pushBack(const T &val);
    void print() const;
    size_t size() const;
    bool contains(const T &val) const;

    void insert(const T& val, size_t pos); //- добавя елемент със стойност val на позиция pos
    void erase(size_t pos); // - изтрива елемента на позиция pos

    static LinkedList intersectSortedLists(const LinkedList& list1, const LinkedList& list2);
    
    class Iterator
    {
        public:
        Iterator(box*);

        bool hasNext() const;
        bool reachedEnd() const;
        T& operator *();
        Iterator& operator ++();
		bool operator!=(const Iterator &other) const;

	private:
        box *curr;
    };

	Iterator begin() const;
	Iterator end() const;
};
//#include "LinkedList.cpp"

template <class T>
LinkedList<T>::LinkedList() : first(nullptr), last(nullptr), numberOfElements(0)
{ /**/
}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> il): LinkedList()
{
    for(const T& el : il)
    {
        pushBack(el);
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <class T>
void LinkedList<T>::clear()
{
    box *crr = this->first;

    while (crr)
    {
        box *save = crr;
        crr = crr->next;
        delete save;
    }

    this->first = nullptr;
    this->last = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other): first(nullptr), last(nullptr), numberOfElements(0)
{
    copy(other);
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T> &other)
{
    box *current = other.first;
    while (!current)
    {
        this->pushBack(current->data);
        current = current->next;
    }
}
// newBox(val, *first) -> (1, *2) -> (2, *3) -> (3, null)

//* void pushFront(const T& val) - добавя елемент със стойност val в началото на списъка
template <class T>
void LinkedList<T>::pushFront(const T &val)
{
    box *newBox = new box(val, this->first);

    if (!this->first)
    {
        this->first = newBox;
        this->numberOfElements++;
        this->last = newBox;
        return;
    }

    this->first = newBox;
    this->numberOfElements++;
}

// (1, *2) -> (2, *3) -> (3, null) -> nullptr
// (1, *2) -> (2, *3) -> (3, newBox*) -> newBox(val, null)

//* void pushBack(const T& val) - добавя елемент със стойност val в края на списъка
template <class T>
void LinkedList<T>::pushBack(const T &val)
{
    if (!this->first)
    {
        pushFront(val);
        return;
    }

    box *newBox = new box(val);
    box *p = this->last;
    p->next = newBox;
    this->last = newBox;
    this->numberOfElements++;
}

template <class T>
void LinkedList<T>::print() const
{
    box *crr = this->first;
    while (crr)
    {
        std::cout << crr->data << " -> ";
        crr = crr->next;
    }
    std::cout << '\n';
}

template <class T>
size_t LinkedList<T>::size() const
{
    return this->numberOfElements;
}

template <class T>
bool LinkedList<T>::contains(const T &val) const
{
    box *crr = first;
    while (crr)
    {
        if (crr->data == val)
        {
            return true;
        }

        crr = crr->next;
    }
    return false;
}

template<class T>
void LinkedList<T>::insert(const T& val, size_t pos)
{
    if(this->numberOfElements < pos)
    {
        throw std::out_of_range("Invalid position");
    }

    if(pos == 0) 
     {
        pushFront(val);
        return;
     }        
     
     if(pos==this->numberOfElements)
     {
         pushBack(val);
         return;
     }
     
    box *crr = first;
    box* newel = new box(val, crr->next);
    size_t count = 0;
    while(count < pos-1)
    {
       crr = crr->next; 
       count++;
    }
    
    crr->next = newel;
}

template<class T>
void LinkedList<T>::erase(size_t pos)
{
    if(numberOfElements == 0)
    {
        throw std::logic_error("Empty list");
    }

    if(numberOfElements < pos)
    {
        throw std::out_of_range("Invalid position");
    }

    size_t elementsPassed = 0;
    box* destroyer = first;
    box* prev = nullptr;
    while(elementsPassed < pos){
        prev = destroyer;
        destroyer = destroyer->next;
        elementsPassed++;
    }

    if(pos == 0)
    {
        if(numberOfElements == 1)
        {
            delete first;
            last = first = nullptr;
            numberOfElements--;
            return;
        }

        first = destroyer->next;
        delete destroyer;
        numberOfElements--;
        return;  
    }

    if(pos == numberOfElements - 1)
    {
        prev->next = nullptr;
        last = prev;
        delete destroyer;
        numberOfElements--;
        return;
    }

    prev->next = destroyer->next;
    delete destroyer;
    numberOfElements--;
}

template<class T>
LinkedList<T> LinkedList<T>::intersectSortedLists(const LinkedList<T>& list1, const LinkedList<T>& list2)
{
    LinkedList<T> intersection;
    box* list1Head = list1.first;
    box* list2Head = list2.first;
    while(list1Head && list2Head)
    {
        if(list1Head->data == list2Head -> data)
        {
            intersection.pushBack(list1Head->data);
            box* curr = list1Head;
            
            while(list1Head->data == curr->data && list1Head->next)
            {
                list1Head = list1Head->next;
            }

            while(list2Head->data == curr->data && list2Head->next)
            {
                list2Head = list2Head->next;
            }
            continue;
        }
        if(list1Head->data < list2Head->data)
        {
            list1Head = list1Head->next;
            continue;
        }

        list2Head = list2Head->next;
    }

    return intersection;
}

template<class T>
LinkedList<T>::Iterator::Iterator(box* elem): curr(elem)
{
 /* */
}

template<class T>
bool LinkedList<T>::Iterator::hasNext() const
{
	return curr->next != nullptr;
}

template<class T>
bool LinkedList<T>::Iterator::reachedEnd() const
{
	return curr == nullptr;
}

template<class T>
T& LinkedList<T>::Iterator::operator *()
{
    if(curr == nullptr)
		throw std::out_of_range("Out of range!\n");

	return curr->data;
}

template<class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator ++()
{
	if(curr == nullptr)
		throw std::out_of_range("Out of range !\n");

	curr = curr->next;
	return *this;
}

template<class T>
bool LinkedList<T>::Iterator::operator!=(const Iterator &other) const
{
	return curr != other.curr;
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const
{
	return LinkedList<T>::Iterator{this->first};
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const
{
    return LinkedList<T>::Iterator{nullptr};
}

#endif