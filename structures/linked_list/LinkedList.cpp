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
  return 0;
}