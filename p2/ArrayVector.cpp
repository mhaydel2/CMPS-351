//
// Created by Milan Haydel on 3/21/21.
//

#include "ArrayVector.h"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;


ArrayVector::ArrayVector(size_t av_size) {
    current_elements = 0;
    total_elements = av_size;
    array_for_vector = new int[total_elements];

}

ArrayVector::ArrayVector(size_t other_sz, const int *other_array) {
    current_elements = 0;
    total_elements = other_sz;
    array_for_vector = new int[other_sz];
    for (int i = 0; i < other_sz; i++) {
        PushBack(other_array[i]);
        current_elements++;
    }
}

void ArrayVector::AddArray(size_t arg_size, int *other_array) {
    for (int i = 0; i < arg_size; i++) {
        PushBack(other_array[i]);
    }
}

int ArrayVector::Get(size_t index) {
    return array_for_vector[index];
}

int ArrayVector::Pop() {
    int last = array_for_vector[current_elements - 1];
    array_for_vector[current_elements - 1] = 0;
    current_elements--;
    return last;
}

void ArrayVector::AddSpace() {
    total_elements = 2 * (total_elements + 1);
    int *newArray = new int[total_elements];
    for (int i = 0; i < current_elements; i++) {
        newArray[i] = array_for_vector[i];
    }

    delete[] array_for_vector;
    array_for_vector = newArray;
}

void ArrayVector::AddSpace(size_t s) {
    total_elements = total_elements + s;
    int *newArray = new int[total_elements];
    for (int i = 0; i < current_elements; i++) {
        newArray[i] = array_for_vector[i];
    }

    delete[] array_for_vector;
    array_for_vector = newArray;
}

void ArrayVector::PushBack(int val) {
    if (current_elements == total_elements) AddSpace();
    array_for_vector[current_elements] = val;
    current_elements++;
}

void ArrayVector::Insert(size_t index, int val) {
    int tempForTemp;
    int temp = array_for_vector[index];
    array_for_vector[index] = val;
    current_elements++;
    if (current_elements < total_elements) {
        for (int i = index + 1; i < current_elements; i++) {
            tempForTemp = array_for_vector[i];
            array_for_vector[i] = temp;
            temp = tempForTemp;
        }
    } else {
        AddSpace();
        for (int i = index + 1; i < current_elements; i++) {
            tempForTemp = array_for_vector[i];
            array_for_vector[i] = temp;
            temp = tempForTemp;
        }
    }
}

void ArrayVector::Remove(int val) {
    int temp;
    for (int i = 0; i < current_elements; i++) {
        if (array_for_vector[i] == val) {
            for (int j = i; j < current_elements; j++) {
                temp = array_for_vector[j + 1];
                array_for_vector[j] = temp;
            }
            current_elements--;
        }
    }
}


int ArrayVector::Sum() {
    int sum = 0;
    for (int i = 0; i < current_elements; i++) {
        sum = sum + array_for_vector[i];
    }
    return sum;
}

int ArrayVector::Max() {
    if (current_elements == 0) return std::numeric_limits<int>::min();
    int max = array_for_vector[0];
    for (int i = 0; i < current_elements; i++) {
        if (array_for_vector[i] > max) max = array_for_vector[i];
    }
    return max;
}

int ArrayVector::Min() {
    if (current_elements == 0) return std::numeric_limits<int>::max();
    int min = array_for_vector[0];
    for (int i = 1; i < current_elements; i++) {
        if (array_for_vector[i] < min) {
            min = array_for_vector[i];
        }
    }
    return min;
}

double ArrayVector::Average() {
    double average = (double) Sum() / current_elements;
    return average;
}

ArrayVector::~ArrayVector() {
    delete[] array_for_vector;
}

void ArrayVector::PrintVector() {
    if (current_elements == 0) cout << "[]" << endl;
    else if (current_elements == 1) cout << "[" << array_for_vector[0] << "]" << endl;
    else {
        cout << "[";
        for (int i = 0; i < current_elements - 1; i++) {
            cout << array_for_vector[i] << ", ";
        }
        cout << array_for_vector[current_elements - 1] << "]" << endl;
    }
}
