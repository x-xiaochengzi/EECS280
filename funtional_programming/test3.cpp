#include "any_of.hpp"
#include "greaterN.hpp"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    list<int> list;
    vector<int> vec;
    int array[10];
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
        vec.push_back(i);
        array[i] = i;
    }
    cout << any_of(list.begin(), list.end(), GreaterN(0)) << endl;
    cout << any_of(vec.begin(), vec.end(), GreaterN(1)) << endl;
    cout << any_of(array, array + 10, GreaterN(10)) << endl;
    return 0;
}