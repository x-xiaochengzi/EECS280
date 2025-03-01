#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
class IntList {
  public:
    // EFFECTS: Constructs an empty list.
    IntList();

    IntList(const IntList &other);
    ~IntList();

    IntList &operator=(const IntList &rhs);

    // EFFECTS:  Returns true if the list is empty.
    bool empty() const;

    // REQUIRES: the list is not empty
    // EFFECTS:  Returns (by reference) the first element.
    int &front();

    // EFFECTS:  Inserts datum at the front of the list.
    void push_front(int data);
    void push_back(int data);
    // REQUIRES: the list is not empty
    // EFFECTS:  Removes the first element.
    void pop_front();

    // MODIFIES: os
    // EFFECTS:  Prints the items in the list, each followed by a space.
    void print(std::ostream &os) const;

  private:
    struct Node {
        int data;
        Node *next;
        Node(int value, Node *ptr) : data(value), next(ptr) {}
        Node(int value) : Node(value, nullptr) {}
        Node() : Node(0, nullptr) {}
    };
    Node *sentinel;

  public:
    class Iterator {
      public:
        Iterator() : ptr(nullptr) {}
        int &operator*() const;
        Iterator &operator++();
        Iterator operator++(int);
        bool operator==(Iterator rhs) const;
        bool operator!=(Iterator rhs) const;

      private:
        Iterator(Node *ptr) : ptr(ptr) {}
        Node *ptr;
        friend class IntList;
    };
    Iterator begin() {
        return Iterator(sentinel->next);
    }
    Iterator end() {
        return Iterator();
    }

  private:
    // EFFECTS:  Removes all the elements from this list.
    void pop_all();

    // EFFECTS:  Adds all elements from other into this list.
    void push_all(const IntList &other);
};
#endif // LINKEDLIST_H
