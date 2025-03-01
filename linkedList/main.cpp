#include "linkedList.hpp"
using namespace std;
int main() {
    IntList list; // ( )
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    cout << "List's interface: ";
    list.print(cout); // 4 3 2 1 0
    cout << endl;
    cout << "Traversal by iterator: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Range-based for loop: ";
    for (auto item : list) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}