//
//

#ifndef PROJECT3_EDITOR_H
#define PROJECT3_EDITOR_H
#include <vector>
#include <string>

class Editor {
public:
    Editor() : cursor_index(0), buffer(0) {}
    void PrintEditor();
    void MoveLeft();
    void MoveRight();
    void BackSpace();
    void Delete();
    void AddChar(char c);
private:
    std::vector<char> buffer;
    size_t cursor_index = 0;
};


#endif //PROJECT3_EDITOR_H
