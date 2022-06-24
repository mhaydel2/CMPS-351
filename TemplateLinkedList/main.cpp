#include <iostream>
#include "LinkedList.h"

int main() {
    // if we allocate our linkedList on the stack,
    // the nodes will be deleted by the destructor
    // when it goes out of scope
    // and the other parts of memory like the count
    // will be reclaimed by the stack frame
    LinkedList<int> linkedList(44);
    linkedList.PushBack(56);
    linkedList.PushBack(99);
    // the first argument number is the index
    // the second argument number will be the number inserted into the list
    linkedList.Insert(2, 999);
    // should print 44->999->56->99->
    linkedList.PrintList();
    // we'll allocate the linked list of doubles on the heap
    // the destructor will delete the nodes
    // but the head and tail pointers and the count variable
    // are on the heap and must also be deleted
    LinkedList<double>* doubleList = new LinkedList<double>(1.4);
    doubleList->PushFront(0.2);
    doubleList->PushBack(3.14);
    doubleList->Erase(0.2);
    doubleList->PrintList();
    // recall that the destructor in the LinkedList handled
    // the new calls in the linked list file
    // the new on line 22 has a corresponding delete here,
    // since the destructor handles the heap allocations
    // happening *inside* of the class
    // and not the heap allocation *for* the class
    delete doubleList;
    return 0;
}
