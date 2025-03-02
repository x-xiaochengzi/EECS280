#include "ArrayIntVector.h"

using namespace std;

// EFFECTS: Creates an empty ArrayIntVector with the specified
//          initial data capacity, or with the default.
ArrayIntVector::ArrayIntVector(int init_capacity)
    : elts_capacity(init_capacity), num_elts(0) {
    data = new int[elts_capacity];
    check_invariants();
}

// Copy Constructor
// EFFECTS: Constructs an ArrayIntVector with the same contents as other.
ArrayIntVector::ArrayIntVector(const ArrayIntVector &other)
    : elts_capacity(other.elts_capacity), num_elts(other.num_elts) {
    data = new int[elts_capacity];
    for (int i = 0; i < num_elts; ++i) {
        data[i] = other.data[i];
    }
    check_invariants();
}

// Assignment Operator
// MODIFIES: this ArrayIntVector
// EFFECTS: Replace this ArrayIntVector's contents with a copy of the contents
//         of rhs.
ArrayIntVector &ArrayIntVector::operator=(const ArrayIntVector &rhs) {
    // self assignment check
    if (this == &rhs) {
        return *this;
    }
    // free old resources
    delete[] data;
    // make a deep copy of the right-hand-side object's resources
    data = new int[rhs.elts_capacity];
    for (int i = 0; i < rhs.num_elts; ++i) {
        data[i] = rhs.data[i];
    }
    check_invariants();
    // shallow copy the non-resources from rhs
    num_elts = rhs.num_elts;
    elts_capacity = rhs.elts_capacity;
    return *this;
}

// Destructor
ArrayIntVector::~ArrayIntVector() {
    delete[] data;
}

// MODIFIES: this ArrayIntVector
// EFFECTS:  Adds value to the end of this ArrayIntVector.
void ArrayIntVector::push_back(int value) {
    check_invariants();
    if (size() == elts_capacity) {
        grow();
    }
    data[num_elts++] = value;
    check_invariants();
}

// REQUIRES: this ArrayIntVector is not empty
// MODIFIES: this ArrayIntVector
// EFFECTS:  Removes the last element in this ArrayIntVector.
void ArrayIntVector::pop_back() {
    check_invariants();
    assert(!empty());

    --num_elts;

    check_invariants();
}

// REQUIRES: 0 <= index < number of elements in this ArrayIntVector
// EFFECTS:  Returns (by reference) the element at the given index.
int &ArrayIntVector::at(int index) {
    check_invariants();
    assert(0 <= index && index <= size());
    return data[index];
}

// REQUIRES: 0 <= index < number of elements in this ArrayIntVector
// EFFECTS:  Returns (by reference) the element at the given index.
const int &ArrayIntVector::at(int index) const {
    assert(0 <= index && index <= size());
    return data[index];
}

// REQUIRES: 0 <= index < number of elements in this ArrayIntVector
// EFFECTS:  Returns (by reference) the element at the given index.
int &ArrayIntVector::operator[](int index) {
    return at(index);
}

// REQUIRES: 0 <= index < number of elements in this ArrayIntVector
// EFFECTS:  Returns (by reference) the element at the given index.
const int &ArrayIntVector::operator[](int index) const {
    return at(index);
}

// EFFECTS:  Returns the number of elements of this ArrayIntVector.
int ArrayIntVector::size() const {
    return num_elts;
}

// EFFECTS:  Returns true if this ArrayIntVector is empty, false otherwise.
bool ArrayIntVector::empty() const {
    return num_elts == 0;
}

// EFFECTS:  Returns the number of elements that can be held in currently
//           allocated storage.
int ArrayIntVector::capacity() const {
    return elts_capacity;
}

// EFFECTS:  Prints to os all elements in this ArrayIntVector in the format:
//           "[ 1, 2, 3, 4, 5 ]" (Note that there is no trailing newline)
void ArrayIntVector::print(std::ostream &os) const {
    os << "[";
    for (int i = 0; i < num_elts; i++) {
        os << " " << data[i];
        if (i < num_elts - 1) {
            os << ",";
        }
    }
    os << " ]";
}

// EFFECTS: Doubles the storage capacity of this ArrayIntVector.
//          More precisely:
//            1. doubles capacity
//            2. allocates a new dynamic array with the new capacity
//            3. copies over the elements from the old data array
//            4. free the memory for the old data array
//            5. sets data to point to the new array
void ArrayIntVector::grow() {
    check_invariants();
    int *items = new int[elts_capacity * 2];
    for (int i = 0; i < num_elts; ++i) {
        items[i] = data[i];
    }
    delete[] data;
    data = items;
    elts_capacity = 2 * elts_capacity;
    check_invariants();
    cout << "grow() was called. Capacity is now " << elts_capacity << "." << endl;
}

// EFFECTS:  Prints to os all elements in the ArrayIntVector in the format:
//           "[ 1, 2, 3, 4, 5 ]" (Note that there is no trailing newline)
std::ostream &operator<<(std::ostream &os, const ArrayIntVector &v) {
    v.print(os);
    return os;
}
