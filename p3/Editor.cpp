//
// Created by peter on 10/24/20.
//

#include "Editor.h"
#include <iostream>
using std::cout;
using std::endl;

void Editor::BackSpace() {
    if (cursor_index>0) {
        int size = buffer.size()-1;
        char arr[size];
        int j=0;
        for (int i = 0; i < buffer.size();i++){
            if (cursor_index-1 != i) {
                arr[j] = buffer.at(i);
                j++;
            }
        }
        buffer.assign(arr, arr+size);
        cursor_index--;
    }
    else return;
}

void Editor::PrintEditor() {
    if (cursor_index==0){
        cout<<"|";
        if (buffer.size()>0){
            for (int i = 0; i < buffer.size(); i++){
                cout<<buffer.at(i);
            }
        }
        cout<<endl;
    }
    else{
        for (int i = 0; i < buffer.size(); i++){
            if (cursor_index-1 == i)
                cout<<buffer.at(i)<<"|";
            else
                cout<<buffer.at(i);
        }
        cout<<endl;
    }
}

void Editor::MoveLeft() {
    if (cursor_index>0) {
        cursor_index--;
    }
    else return;
}

void Editor::MoveRight() {
    if (cursor_index<buffer.size()) {       //deleted +1 from size
        cursor_index++;
        //cout<<"Moving right"<<endl;
    }
    else return;
}

void Editor::Delete() {
    if (cursor_index>=0 && cursor_index<buffer.size()) {
        int size = buffer.size() - 1;
        char arr[size];
        int j = 0;
        for (int i = 0; i < buffer.size(); i++) {
            if (cursor_index != i) {
                arr[j] = buffer.at(i);
                j++;
            }
        }
        buffer.assign(arr, arr + size);
    }
    else return;
}

void Editor::AddChar(char c) {
    auto pos = buffer.begin() + cursor_index;
    buffer.insert(pos, c);
    cursor_index++;
}
