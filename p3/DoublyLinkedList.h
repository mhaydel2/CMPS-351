//
//

#ifndef PROJECT3_DOUBLYLINKEDLIST_H
#define PROJECT3_DOUBLYLINKEDLIST_H
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
template <class T>
class DNode {
public:
    DNode(const T &e = T(), DNode *n = nullptr, DNode *p = nullptr) : element(e), next(n), previous(p) {}
    ~DNode() {}
    T element; //content of node
    DNode *next; //reference to next node
    DNode *previous; //reference to previous node
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    explicit DoublyLinkedList(T elem);
    void Insert(int index, T elem);
    void MoveLeft();
    void MoveRight(int index);
    void DeleteBefore(int index);
    void DeleteAfter(int index);
    void PrintCheck();
    DNode<T>* cursor;       // '|' will be in front of this node
    DNode<T>* head;
    void Erase();
    size_t count;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {   //default constructor
    count = 0;
    cursor = nullptr;
    head = nullptr;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T elem) {
    count = 1;
    head = new DNode<T>(elem);
    cursor = head;
}

template<class T>
void DoublyLinkedList<T>::Insert(int index, T elem) {   // use cursor to insert
    DNode<T>* newN = new DNode<T>(elem);
    //if there is no data
    if (head == nullptr && cursor == nullptr){
        count = 1;
        head = newN;
        cursor = head;
        delete newN;
    }
    //if cursor is at the end of the line
    else if (index == count){
        DNode<T>* node = head;
        for (int i=0; i<index-1; i++){
            node = node->next;
        }
        if (node != nullptr){
            newN->previous = node;
            node->next = newN;
            cursor = newN;
            count++;
            delete newN;
        }
        else {
            delete newN;
        }
    }

    //if cursor is at the beginning
    else if (index == 0){
        newN->next = head;
        head = newN;
        cursor = head;
        count++;
        delete newN;
        //PrintCheck();
        //cout<<"index: "<<index+1<<" and count: "<<count<<endl;
    }

    //if cursor is not at the end (in mid)
    else if (index < count){
        DNode<T>* prev = nullptr;
        DNode<T>* node = head;
        for (int i=0; i<index; i++){
            prev = node;
            node = node->next;
        }
        if (prev != nullptr){
            prev->next = newN;
            newN->previous = prev;
            newN->next = node;
            node->previous = newN;
            cursor = newN;
            count++;
            delete newN;
        }
        else {
            delete newN;
        }
        delete prev;
        delete node;
    }
}

template<class T>
void DoublyLinkedList<T>::DeleteBefore(int index) {
    //if there is one character away from being at the beginning of the line
    if (index == 1){
        //if there is still remaining data after the cursor
        if (head->next != nullptr) {
            cursor = head->next;
            cursor->previous = nullptr;
            head = cursor;
        }
        //if there is no remaining data
        else {
            cursor = nullptr;
            head = nullptr;
            //PrintCheck();
            //delete temp;
        }
    }

    //if there is at least two characters away from the beginning of the line
    else{
        auto past = cursor;
        //PrintCheck();
        cursor = cursor->previous;
        cursor->next = past->next;

        //this ensures move left and right will fcn properly
        if (cursor->next != nullptr)
            (cursor->next)->previous = cursor;
        //if cursor is at beginning
        if (cursor->previous == nullptr)
            head = cursor;
    }
    count--;
    //PrintCheck();
    return;
}

template<class T>
void DoublyLinkedList<T>::DeleteAfter(int index) {
    if (index == 0) {
        auto temp = head->next;
        if (temp != nullptr) {
            cursor = head->next;
            cursor->previous = nullptr;
            head = cursor;
            count--;
        }
        else {
            delete cursor;
            delete head;
            cursor = nullptr;
            head = nullptr;
            count--;
        }
    }
    else {
        if (head->next != nullptr) {
            auto next = cursor->next;
            cursor->next = next->next;
            if (next->next != nullptr)
                (cursor->next)->previous = cursor;
            count--;
        }
    }
    //cout<<count<<endl;
    //PrintCheck();
}

template<class T>
void DoublyLinkedList<T>::Erase() {
    if (head != nullptr) {
        DNode<T> *to_delete = head;
        while (to_delete != nullptr) {
            DNode<T> *next = to_delete->next;
            delete to_delete;
            to_delete = next;
        }
    }
}

template<class T>
void DoublyLinkedList<T>::MoveLeft() {
    auto past = cursor->previous;
    if (past != nullptr){
        cursor = past;
        }
    /*else{         attempt at changing cursor where previous and element are empty and only contains next as head.
     *              this did not work, I opted for just relying on the change of the cursor_index in the insert
     *              method : if (index == 0) // if cursor is at the beginning
        delete cursor;
        cursor->next = head;
        //head->previous = cursor;
        cout<<"Done"<<endl;
        if (head->previous == cursor) cout<<"True"<<endl;

    }*/
    else return;
}

template<class T>
void DoublyLinkedList<T>::MoveRight(int index) {
    //cout<<index<<endl;
    if (index == 0){
        PrintCheck();}
    else if (cursor->next != nullptr) {
        auto pres = cursor->next;
        cursor = pres;

        //PrintCheck();
    }
    else return;
}

template<class T>
void DoublyLinkedList<T>::PrintCheck() {
    cout<<"Element: ";
    if (cursor != nullptr)
        cout<<(cursor->previous)->element;
    else
        cout<<"none";

    cout<<" Previous: ";
    if (cursor->previous!= nullptr)
        cout<<(cursor->previous)->element;
    else
        cout<<"none";

    cout<<" Next: ";
    if (cursor->next!= nullptr)
        cout<<(cursor->next)->element<<endl;
    else
        cout<<"none"<<endl;
}


#endif //PROJECT3_DOUBLYLINKEDLIST_H
