//
//

#ifndef PROJECT3_LINKEDEDITOR_H
#define PROJECT3_LINKEDEDITOR_H
#include <stdlib.h>
#include "DoublyLinkedList.h"

class LinkedEditor {
public:
    LinkedEditor();
    void PrintEditor();
    void MoveLeft();
    void MoveRight();
    void AddChar(char c);
    void BackSpace();
    void Delete();
    ~LinkedEditor();
private:
    DoublyLinkedList<char>* buffer;
    size_t cursor_index;
    size_t character_count;
    size_t first=0;
};


#endif //PROJECT3_LINKEDEDITOR_H
