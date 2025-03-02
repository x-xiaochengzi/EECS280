#include <iostream>
using namespace std;

void reverse(int *left, int *right) {
    if (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        reverse(left + 1, right - 1);
    }
}
void print(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int factorial(int n, int resultSoFar) {
    if (n == 0 || n == 1) {
        return resultSoFar;
    } else {
        return factorial(n - 1, n * resultSoFar);
    }
}
int main() {
    const int SIZE = 8;
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    reverse(array, array + SIZE - 1); // reverse whole array
    print(array, SIZE);
    reverse(array + 1, array + 3); // reverse elements 1-3
    print(array, SIZE);
    return 0;
}
