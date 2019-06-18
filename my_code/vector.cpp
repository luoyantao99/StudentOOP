#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}


MyVec::MyVec() {
    sz = 0;
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}

MyVec::MyVec(const MyVec& v2) {
    sz = v2.sz;
    capacity = v2.capacity;
    data = new int[v2.capacity];
    for (int i = 0; i < sz; i++)
    {
        data[i] = v2.data[i];
    }
}

MyVec::~MyVec() {
    if (data != nullptr){
        delete[] data;
    }
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if (this != &v2)
    {
        if (data != nullptr){
            delete[] data;
        }
        
        sz = v2.sz;
        capacity = v2.capacity;
        data = new int[v2.capacity];
        for (int i = 0; i < sz; i++)
        {
            data[i] = v2.data[i];
        }
    }
    return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(const MyVec& v1, const MyVec& v2) {
    if (v1.size() != v2.size()) { return false; }
    for (int i = 0; i<v1.size(); i++){
        if (v1[i] != v2[i]) { return false; }
    }
    return true;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
    if (sz == capacity){
        capacity *= 2;
        int* new_data = new int[capacity];
        for (int i=0; i<size(); i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[sz++] = val;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    return data[i];
}
