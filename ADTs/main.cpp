//
// Created by xzc on 2025/2/27.
//

#include <cassert>
#include <iostream>
#include "Triangle.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
    Triangle t1;
    cout << t1.perimeter() << endl;
    Triangle t2(3, 4, 5);
    cout << t2.perimeter() << endl;
    t2.scale(2);
    assert(t2.perimeter() == 24);
    return 0;
}