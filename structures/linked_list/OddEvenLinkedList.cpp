#include "LinkedList.hpp"
//https://leetcode.com/problems/odd-even-linked-list/
//Solution is implemented in the LinkedList oddEvenList method

void runTestForList(LinkedList<int>& testList){
  std::cout << "========================" << std::endl;
  testList.print();
  testList.oddEvenList();
  testList.print();
  std::cout << "========================" << std::endl;
}

void runSampleTests(){
  LinkedList<int> test1List = {1, 2, 3, 4, 5};
  LinkedList<int> test2List = {2, 1, 3, 5, 6, 4, 7};

  runTestForList(test1List);
  runTestForList(test2List);
}

int main(){
  runSampleTests();

  return 0;
}