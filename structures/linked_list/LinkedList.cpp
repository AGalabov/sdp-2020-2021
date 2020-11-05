#include"LinkedList.hpp"


int main(){

  LinkedList<int> ll;

  ll.print(); // \n
  std::cout << "Size: " << ll.size() << std::endl; //

  ll.pushBack(1);
  ll.pushBack(2);
  ll.pushBack(3);

  ll.print(); // 1 -> 2 -> 3 \n
  std::cout << "Size: " << ll.size() << std::endl; //

  ll.pushFront(4);
  ll.pushFront(5);
  ll.pushFront(6);
  
  ll.print(); // 6 -> 5 -> 4 -> 1 -> 2 -> 3
  std::cout << "Size: " << ll.size() << std::endl; //

  std::cout << std::boolalpha << ll.contains(1)  << " " << ll.contains(2) << " " 
            << ll.contains(10) << " " << ll.contains(0) << std::endl;


  ll.insert(10,0);
  ll.print();

  
  //throws std::logic_error
  //LinkedList<int> ll3;
  //ll3.erase(0);
  
  //throws std::out_of_range
  //ll.erase(100);
  
  //ll.insert(10, 100);
  // LinkedList<int> ll2 = ll;
  // ll2.print();

  // ll.pushFront(10);
  // ll2.pushBack(10);

  // std::cout << "---------" << std::endl;
  // ll.print();
  // ll2.print();

  // ll2 = ll;
  // ll2.print();


  std::cout << " ------Erase from list with one element --- " << std::endl;
  LinkedList<int> listWithOneElement = {1};
  listWithOneElement.print();
  listWithOneElement.erase(0);
  listWithOneElement.print();

  //test to see if tail is ok
  listWithOneElement.pushBack(42);
  listWithOneElement.print();

  //test to see if head is ok
  listWithOneElement.pushFront(4);
  listWithOneElement.print();

  std::cout << "------Erase from start,end and middle of list --- " << std::endl;
  ll.erase(0);
  ll.print(); // 6 -> 5 -> 4 -> 1 -> 2 -> 3

  ll.erase(ll.size() - 1); // 6 -> 5 -> 4 -> 1 -> 2 ->
  ll.print();

  ll.erase(2);  // 6 -> 5 -> 1 -> 2 ->
  ll.print();

  //test to see if tail is ok
  ll.pushBack(42);
  ll.print();

  //test to see if head is ok
  ll.pushFront(4);
  ll.print();

  std::cout << "------ Intersection of two sorted lists ---" << std::endl;
  LinkedList<int> sortedList1 = { 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10 };
  LinkedList<int> sortedList2 = {};

  LinkedList<int>::intersectSortedLists(sortedList1, sortedList2).print();

  sortedList2.pushBack(3);
  sortedList2.pushBack(5);
  sortedList2.pushBack(5);
  LinkedList<int>::intersectSortedLists(sortedList1, sortedList2).print();

  LinkedList<int> sortedList3 = {0, 1, 5, 7, 8, 11};
  LinkedList<int>::intersectSortedLists(sortedList1, sortedList3).print();


  std::cout<<"------ Iterator testing --- " <<std::endl;
  for(LinkedList<int>::Iterator it = sortedList1.begin(); it != sortedList1.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  return 0;
}