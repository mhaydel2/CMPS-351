#include <iostream>
#include <fstream>
#include <random>
#include "ArrayVector.h"
#include <string>
using std::cout;
using std::endl;

int main() {
    int score;
    std::ifstream grades_input_file;
    grades_input_file.open("grades.txt");
    ArrayVector grade_vector(5);
    while (grades_input_file.is_open() && !grades_input_file.eof()){
        grades_input_file >> score;
        grade_vector.PushBack(score);
    }
    grade_vector.PrintVector();
    std::cout << "The worst grade is: " << grade_vector.Min() << std::endl;
    std::cout << "The best grade is: " << grade_vector.Max() << std::endl;
    std::cout << "The average grade is: " << grade_vector.Average() << std::endl;
    grades_input_file.close();
    return 0;
}
