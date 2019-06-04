#include <iostream>
#include <string>
#include <vector>
#include "basics.h"

using namespace std;

/*
 * increment arg passed by copy
 * */
void inc_pass_copy(int j) {
    j++;
}

/*
 * increment arg passed by reference
 * */
void inc_pass_ref(int& j) {
    j++;
}

/*
 * Fill a vector with n elements from 1 to n.
 * 1st item == 1, 2nd item == 2, etc.
 * 0 filled for you.
 * Use `push_back()` to fill the vector.
 * */
void fill_vector(vector<int>& v, int n) {
    for (int i=0; i<n; i++){
        v.push_back(i);
    }
}

/*
 * Print all elements in a vector. Use a ranged for!
 * */
void print_vector(const vector<int>& v) {
    for (int i :v){
        cout << i << " ";
    }
    cout << endl;
}

/*
 * Print a pair of coordinates.
 * Output should look like "x = 9, y = 2".
 * */
void print_coords(coord pos) {
    cout << "(" << pos.x <<", " << pos.y << ")";
}

/*
 * Square an integer.
 * */
int square(int n) {
    return n*n;
}

/*
 * Square a double.
 * */
double square(double d) {
    return d*d;
}

/*
 * Get the absolute value of a number.
 * */
int my_abs(int n) {
    return abs(n);
}

/*
 * Sum from 0 to n using a `while` loop.
 * */
int sum(int n) {
    int sum = 0;
    int i = 0;
    while(i<n){
        sum += i;
        i++;
    }
    return sum;
}

/*
 * Sum from 0 to n using a `for` loop.
 * */
int sum2(int n) {
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += i;
    }
    return sum;
}

/*
 * say() is built for you!
 * */
void say(std::string s) {
    cout << s << endl;
}


/*
 * Use a ranged for to pull a string apart into its bits.
 * */
void pull_apart_string(std::string s) {
    for (char c : s){
        cout << c << " ";
    }
}

