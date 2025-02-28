#include "intset.h"
#include <iostream>
using namespace std;
int main() {
    IntSet set;
    set.insert(7);
    set.insert(32);
    set.insert(32);

    cout << "Size: " << set.size() << endl; // prints 2
    set.print(cout);                        // prints { 7, 32 } in some arbitrary order
    cout << endl;
    set.insert(42);
    set.remove(32);
    set.remove(32);

    cout << "Contains 32? " << set.contains(32) << endl; // prints 0 (false)
    cout << "Contains 42? " << set.contains(42) << endl; // prints 1 (true)
    cout << set << endl;
    cout << set[32] << endl; // prints 0
    cout << set[42] << endl; // prints 1
}