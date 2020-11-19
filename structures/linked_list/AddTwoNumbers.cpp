#include "LinkedList.hpp"

//https://leetcode.com/problems/add-two-numbers/
//soultion implemented in LinkedList method addTwoNumbers 
//original solution by Nikolai, reworked to fit the LinkedList class


void testSum1(){
    LinkedList<int> summand1 = {2, 4, 3};
    LinkedList<int> summand2 = {5, 6, 4};
    LinkedList<int> result = LinkedList<int>::addTwoNumbers(summand1, summand2);
    result.print();
}

void testSum2(){
    LinkedList<int> summand1 = {0};
    LinkedList<int> summand2 = {0};
    LinkedList<int> result = LinkedList<int>::addTwoNumbers(summand1, summand2);
    result.print();
}

void testSum3(){
    LinkedList<int> summand1 = {9, 9, 9, 9};
    LinkedList<int> summand2 = {9, 9, 9, 9, 9, 9, 9};
    LinkedList<int> result = LinkedList<int>::addTwoNumbers(summand1, summand2);
    result.print();
}

void runExampleTests(){
    testSum1();
    testSum2();
    testSum3();
}

int main(){
    runExampleTests();
}