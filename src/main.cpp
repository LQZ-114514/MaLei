#include "MaLei/LinkedList.h"

int main() 
{
    MaLei::LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.print();
    list.insert(1, 6767);
    list.print();
    list.pushFront(919191);
    list.print();
    std::cout<<list.find(2)<<std::endl;
    list.remove(2);
    list.print();
    std::cout<<list.find(2)<<std::endl;
    std::cout<<list.get(1)<<std::endl;
    list.remove(2);
    std::cout<<list.get(0)<<std::endl;
    list.print();
    list.reverse();
    list.print();
    list.pushBack(2567);
    list.print();
    std::cout<<list.middle()<<std::endl;
    list.pushBack(245);
    list.print();
    std::cout<<list.middle()<<std::endl;
    list.pushBack(3434);
    list.print();
    std::cout<<list.middle()<<std::endl;
    std::cout<<list.kthFromEnd(2)<<std::endl;
    std::cout<<list.kthFromEnd(3)<<std::endl;
    std::cout<<list.kthFromEnd(1)<<std::endl;
    list.reverseBetween(2,6);
    list.print();
    list.insert(3,999);
    list.insert(3,999);
    list.insert(3,999);
    list.insert(3,999);

    list.print();

    list.removeDuplicates();
    list.print();
    list.partition(2000);
    list.print();
    
    list.sort();
    list.print();




    return 0;
}