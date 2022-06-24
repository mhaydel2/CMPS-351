//
//

#include "LinkedEditor.h"
#include <iostream>

void LinkedEditor::PrintEditor() {
    if (cursor_index==0) {
        std::cout << "|";
        for (auto traverser = buffer->head; traverser != nullptr; traverser=traverser->next) {
            std::cout << traverser->element;
        }
    }
    else{
        for (auto traverser = buffer->head; traverser != nullptr; traverser=traverser->next) {
        std::cout << traverser->element;
        if (traverser == buffer->cursor)
            std::cout << "|";
        }
    }
    std::cout << std::endl;
}

void LinkedEditor::MoveLeft() {
    if (cursor_index>0) {
        //std::cout<<"move left"<<std::endl;
        buffer->MoveLeft();
        cursor_index--;
        //std::cout<<cursor_index<<std::endl;
    }
    //else if (cursor_index == 0) return;
    else return;
}

void LinkedEditor::MoveRight() {
    if (cursor_index<buffer->count) {
        buffer->MoveRight(cursor_index);
        cursor_index++;
    }
    //cout<<cursor_index<<endl;
    else return;
}

void LinkedEditor::BackSpace() {
    //std::cout<<cursor_index<<std::endl;
    //cout<<cursor_index<< " and " <<character_count<<endl;
    if (cursor_index > 0 && cursor_index <= character_count){
        //cout<<cursor_index<< " and " <<character_count<<endl;
        buffer->DeleteBefore(cursor_index);
        cursor_index--;
        character_count--;
        //std::cout<<cursor_index<<std::endl;
    }
    //cout<<cursor_index<< " and " <<character_count<<" and "<<buffer->count<<endl;
    else return;
}

void LinkedEditor::Delete() {
    if (cursor_index >= 0 && cursor_index < character_count) {
        //cout<<cursor_index<< " and " <<character_count<<endl;     //check
        buffer->DeleteAfter(cursor_index);
        character_count--;
    }
    else return;
}

void LinkedEditor::AddChar(char c) {
    buffer->Insert(cursor_index, c);
    cursor_index++;
    character_count++;
}


LinkedEditor::LinkedEditor() {
    buffer = new DoublyLinkedList<char>();
    cursor_index=0;
    character_count=0;
}

LinkedEditor::~LinkedEditor() {
    delete buffer;
}


