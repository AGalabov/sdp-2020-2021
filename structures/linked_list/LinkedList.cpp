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
  LinkedList<int> llInit = { 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10 };
  return 0;
}