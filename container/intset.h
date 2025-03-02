#ifndef INTSET_H
#define INTSET_H
#include <iostream>
class IntSet {
  public:
    // Maximum size of a set.
    static const int MAX_SIZE;

    // EFFECTS:  Initializes this set to be empty.
    IntSet();

    // REQUIRES: size() < MAX_SIZE
    // MODIFIES: *this
    // EFFECTS:  Adds value to the set, if it isn't already in the set.
    void insert(int value);

    // MODIFIES: *this
    // EFFECTS:  Removes value from the set, if it is in the set.
    void remove(int value);

    // EFFECTS:  Returns whether value is in the set.
    bool contains(int value) const;

    // EFFECTS:  Returns the number of elements.
    int size() const;

    // EFFECTS:  Prints out the set in an arbitrary order.
    void print(std::ostream &os) const;

    IntSet operator+(const IntSet &rhs) const;

    bool operator[](int value) const;

  private:
    int
    indexOf(int value) const;

  private:
    int elements[MAX_SIZE];
    int num_elements;

    // INVARIANTS:
    // 0 <= num_elements <= MAX_SIZE
    // the first num_elements items in elements are the items in the set
    // the first num_elements items in elements contain no duplicates
};
std::ostream &operator<<(std::ostream &os, const IntSet &set);
#endif // INTSET_H
