#include <iostream>
#include "Editor.h"
#include "LinkedEditor.h"
#include <string>

/*  Milan Haydel
    C00419477
    CMPS 351
    Certificate of Authenticity: I certify that the code in the
        method functions including method function main of this
        project are entirely my own work.
 */

int main() {
    std::string user_input;
    /*
     * Below, we define two types of text editors
     * One uses a c++ vector type to hold characters
     * and the cursor position. This is the Editor object.
     *
     * The other editor of type LinkedEditor uses
     * a generic doubly linked list behind the scenes.
     * It is up to you to modify the this DoublyLinkedList
     * structure with whatever methods you want to hold
     * nodes that contain a character. In the sample
     * representation of a LinkedEditor,  I have a pointer
     * to nodes that can be "moved around" to represent
     * a cursor moving around. A backspace operation
     * can be thought of as deleting the node pointed to
     * by the cursor. Deleting a character can be thought of
     * as deleting the cursor's next node. Inserting a
     * character adds a node after the cursor and before the
     * cursor's current next node. this is visualized below
     *
     *   cursor
     *   -------       -------
     *   |  a  | => <= |  c  |
     *   ------        -------
     *
     *   after we type the character 'b'
     *                 cursor
     *   -------       -------       -------
     *   |  a  | => <= |  b  | => <= |  c  |
     *   ------        -------       -------
     */
    Editor ed;
    LinkedEditor led;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    char c;
    int go=1;
    /*
     * The code below forms our editor loop. For now I
     * have just added printing so you get a feel for how
     * the editor can be interacted with. Your job is to
     * finish the method calls for our two editor objects.
     */
    while(go==1) {
        std::getline(std::cin, user_input);
        if (user_input == "left") {
            ed.MoveLeft();
            led.MoveLeft();
        }
        else if (user_input == "right") {
            ed.MoveRight();
            led.MoveRight();
        }
        else if (user_input == "backspace") {
            ed.BackSpace();
            led.BackSpace();
        }
        else if (user_input == "delete") {
            ed.Delete();
            led.Delete();
        }
        else if (user_input == "exit"){
            go = 0;
        }
        else {
            for (int i=0; i<user_input.length(); i++){
                c = user_input[i];
                ed.AddChar(c);
                led.AddChar(c);
            }
        }
        ed.PrintEditor();
        led.PrintEditor();
    }
}
