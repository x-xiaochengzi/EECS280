#include "intset.h"
#include <cassert>
IntSet::IntSet() : num_elements(0) {}

int IntSet::indexOf(int value) const {
    for (int i = 0; i < num_elements; ++i) {
        if (elements[i] == value) {
            return i;
        }
    }
    return -1;
}

bool IntSet::contains(int value) const {
    return indexOf(value) != -1;
}

void IntSet::insert(int value) {
    assert(size() < MAX_SIZE);
    if (!contains(value)) {
        elements[num_elements++] = value;
    }
}

void IntSet::remove(int value) {
    int index = indexOf(value);
    if (index != -1) {
        elements[index] = elements[--num_elements];
    }
}

int IntSet::size() const {
    return num_elements;
}

void IntSet::print(std::ostream &os) const {
    os << "{ ";
    for (int i = 0; i < num_elements; ++i) {
        os << elements[i] << " ";
    }
    os << "}";
}
IntSet IntSet::operator+(const IntSet &rhs) const {
    IntSet result = *this;
    for (int i = 0; i < rhs.num_elements; ++i) {
        if (!contains(rhs.elements[i])) {
            result.insert(rhs.elements[i]);
        }
    }
    return result;
}
bool IntSet::operator[](int value) const {
    return contains(value);
}
std::ostream &operator<<(std::ostream &os, const IntSet &set) {
    set.print(os);
    return os;
}