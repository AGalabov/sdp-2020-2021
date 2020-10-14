# Практикум (15.10.2020) - Свързан списък

## Зад.1 Имлементирайте шаблонен клас LinkedList реализиращ едносвързан списък. Класът трябва да съдържа като минимум член-функциите от долния списък

* void pushFront(const T& val) - добавя елемент със стойност val в началото на списъка
* void pushBack(const T& val) - добавя елемент със стойност val в края на списъка
* void insert(const T& val, size_t pos) - добавя елемент със стойност val на позиция pos
* void erase(size_t pos) - изтрива елемента на позиция pos
* size_t size() - връща текущия размер на списъка
* bool contains(const T& val) - проверява дали списъка съдържа елемент със стойност val

## Зад.2 Имплементирайте функция, която по дадени два сортирани свързани списъка да връща нов свързан списък съдържащ копия на всички елементи съдържащи се и в двата списъка