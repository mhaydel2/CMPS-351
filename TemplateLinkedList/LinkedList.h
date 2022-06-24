//
// Created by peter on 4/7/21.
//

#ifndef TEMPLATEDLINKEDLIST_LINKEDLIST_H
#define TEMPLATEDLINKEDLIST_LINKEDLIST_H

template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    // a constructor for linked list nodes
    Node(T data, Node<T>* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

template<class T>
class LinkedList {
private:
    int count;
    Node<T>* head;
    Node<T>* tail;
public:
    // the default constructor sets the count to 0
    LinkedList();
    // create a linked list from a piece of data
    // by creating a head node
    LinkedList(T data);
    // pushes a new node containing data to the front of the
    // linked list
    void PushFront(T data);
    // pushes a new node containing data to the front of the
    // linked list
    void PushBack(T data);
    // used to remove the first node containing the argument content
    // starting from head
    bool Erase(T data);
    // remove the first element from a list
    void PopFront();
    // remove the last element from a list
    void PopBack();
    // print the linked list
    void PrintList();
    // free the memory for the linked list
    void Insert(size_t index, T elem);
    // consider implementing the Remove method below
    // which deletes the node at a given index in a similar
    // manner to insert
    void Remove(size_t index);
    // delete the nodes in the linked list
    ~LinkedList();
};


template<class T>
LinkedList<T>::LinkedList(T data) {
    count = 1;
    head = new Node<T>(data);
    tail = head;
}

template<class T>
void LinkedList<T>::PushFront(T data) {
    count++;
    Node<T>* newHead = new Node<T>(data);
    if (head != nullptr && tail != nullptr) {
        newHead->next = head;
        head = newHead;
    }
    else {
        head = newHead;
        tail = newHead;
    }
}

template<class T>
void LinkedList<T>::PushBack(T data) {
    count++;
    auto newTail = new Node<T>(data);
    if (head != nullptr && tail != nullptr) {
        tail->next = newTail;
        tail = newTail;
    }
    else {
        head = newTail;
        tail = newTail;
    }
}

template<class T>
bool LinkedList<T>::Erase(T data) {
    Node<T>* prev = nullptr;
    for (Node<T>* iter = head; iter != nullptr; iter = iter->next) {
        if (iter->data == data) {
            if (iter == head) {
                PopFront();
                return true;
            }
            else if (iter == tail) {
                PopBack();
                return true;
            }
            else {
                prev->next = iter->next;
                delete iter;
                count--;
                return true;
            }
        }
        prev = iter;
    }
    return false;
}

template<class T>
void LinkedList<T>::PopFront() {
    if (head == nullptr)
        return;
    else if (head == tail) {
        count --;
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        count--;
        auto next = head->next;
        delete head;
        head = next;
    }
}

template<class T>
void LinkedList<T>::PopBack() {
    if (tail == nullptr)
        return;
    else if (head == tail) {
        count --;
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        count --;
        Node<T>* iter;
        // we need to advance our pointer until it looks at the
        // last node in the linked list
        for (iter = head; iter->next != tail; iter = iter->next)
            continue;
        iter->next = nullptr;
        delete tail;
        tail = iter;
    }
}

template<class T>
void LinkedList<T>::PrintList() {
    // for an arbitrary piece of data we can't be sure that
    // it's printable
    for (Node<T>* iter = head; iter != nullptr; iter = iter->next) {
        std::cout << iter->data << "->";
    }
    std::cout << std::endl;
}

/*
 * If we insert at index 0, then the new value
 * gets put into a node that becomes the head of the list.
 * Otherwise we find a node, insert at that spot
 * and then shift the rest of the linked list
 */
template<class T>
void LinkedList<T>::Insert(size_t index, T elem) {
    if (index >= count) {
        std::cout << "Give me a valid index within the size " << count << std::endl;
        return;
    }
    if (index == 0) {
        PushFront(elem);
        count++;
    }
    else {
        Node<T>* prev = nullptr; // here is my "little brother" who follows "big brother"
        Node<T>* node = head; // here is my "big brother" who moves as the index increments
        for (int i = 0; i < index; i++) {
            // each time
            prev = node; // little brother goes to big brother's position
            // when big brother is about to take a step
            node = node->next; // this how we advance a pointer variable

        }
        // now big brother has found the node that we are shifting over
        // one unit to the right
        if (prev != nullptr) {
            // little brother will add the new node containing elem at
            // big brother's slot
            auto newNode = new Node<T>(elem);
            prev->next = newNode;
            // and then our newNode's next refers to the node that "big brother" found
            newNode->next = node;
            count++;
        }
    }
}

template<class T>
LinkedList<T>::LinkedList() {
    count = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    if (head == nullptr)
        return;
    Node<T>* prev = nullptr;
    for (auto iter = head; iter != nullptr; iter = iter->next) {
        if (prev != nullptr)
            delete prev;
        prev = iter;
    }
    if (prev != nullptr)
        delete prev;
}


#endif //TEMPLATEDLINKEDLIST_LINKEDLIST_H
