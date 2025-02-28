#include "lab02.h"

#include <cassert>
#include <iostream>
using namespace std;

// REQUIRES: there are at least n elements in arr;
//           n >= 0
// MODIFIES: cout
// EFFECTS:  Prints out the first n elements in arr to standard
//           output. Each element is followed by a space, including
//           the last element.
// NOTE:     You must use traversal by index.
void printArrayIndex(const int arr[], int n) {
    assert(n >= 0);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

// REQUIRES: there are at least n elements in arr;
//           n >= 0
// MODIFIES: cout
// EFFECTS:  Prints out the first n elements in arr to standard
//           output. Each element is followed by a space, including
//           the last element.
// NOTE:     You must use traversal by pointer.
void printArrayPointer(const int arr[], int n) {
    assert(n >= 0);
    for (const int *ptr = arr; ptr < arr + n; ++ptr) {
        cout << *ptr << " ";
    }
}

// REQUIRES: there are at least n elements in arr;
//           n >= 1
// MODIFIES: the elements in arr
// EFFECTS:  All elements are "shifted" right by one unit, with the
//           last element wrapping around to the beginning.
// EXAMPLE:  If arr contains [0,1,3,3,4], it would be modified to
//           contain [4,0,1,3,3]
// NOTE:     You must use traversal by pointer.
//           You may not use an extra array.
void slideRight(int arr[], int n) {
    assert(n >= 1);
    if (n >= 2) {
        int temp = *(arr + n - 1);
        for (int *ptr = arr + n - 2; ptr != arr - 1; --ptr) {
            *(ptr + 1) = *ptr;
        }
        *arr = temp;
    }
}

// REQUIRES: there are at least n elements in arr;
//           n >= 0
// MODIFIES: the elements in arr
// EFFECTS:  Reverses the order of the elements in arr.
// EXAMPLE:  If arr contains, [1,2,3,4,5], it would be modified to
//           contain [5,4,3,2,1]
// NOTE:     You must use traversal by pointer.
//           You may not use an extra array.
void flip(int arr[], int n) {
    assert(n >= 0);
    for (int *left = arr, *right = arr + n - 1; left < right; ++left, --right) {
        int temp = *left;
        *left = *right;
        *right = temp;
    }
}

// REQUIRES: there are at least n elements in arr;
//           n >= 0;
//           the elements of arr are sorted in ascending order;
//           there may be duplicates
// MODIFIES: the elements in arr
// EFFECTS:  Removes duplicate elements from arr. Returns the number
//           of unique elements, and modifies arr to contain those
//           unique elements in sorted order at the beginning. The
//           values that come after the unique elements are
//           unspecified (they are allowed to be anything).
// EXAMPLE:  If arr contains, [1,2,2,3,3], it would be modified to
//           contain [1,2,3,?,?] (where ? means the value can be
//           anything), and the return value would be 3
// NOTE:     You must use traversal by pointer.
//           Your solution must be in-place and run in linear time.
int removeDuplicates(int arr[], int n) {
    assert(n >= 0);
    if (n == 0) {
        return 0;
    }
    int *pre = arr;
    for (int *cur = arr + 1; cur < arr + n; ++cur) {
        if (*cur != *pre) {
            *(pre + 1) = *cur;
            ++pre;
        }
    }
    return pre - arr + 1;
}
