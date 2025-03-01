#include "any_of.hpp"
#include "greaterN.hpp"
#include <iostream>
using namespace std;
int main() {
    GreaterN greater0(0);
    GreaterN greater32(32);
    GreaterN greater212(212);

    cout << greater0(-5) << endl; // 0
    cout << greater0(3) << endl;  // 1
    cout << greater0(-5) << endl; // 0 (false)
    cout << greater0(3) << endl;  // 1 (true)

    cout << greater32(9) << endl;  // 0 (false)
    cout << greater32(45) << endl; // 1 (true)

    cout << greater212(42) << endl;  // 0 (false)
    cout << greater212(451) << endl; // 1 (true)
    cout << "========================================" << endl;

    return 0;
}