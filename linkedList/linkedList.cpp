#include "linkedList.hpp"
#include <cassert>
IntList::IntList() : sentinel(new Node) {}
IntList::IntList(const IntList &other) : IntList() {
    push_all(other);
}
IntList &IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        pop_all();
        push_all(rhs);
    }
    return *this;
}
IntList::~IntList() {
    pop_all();
}
bool IntList::empty() const {
    return sentinel->next == nullptr;
}
int &IntList::front() {
    assert(!empty());
    return sentinel->next->data;
}
void IntList::push_front(int value) {
    Node *node = new Node(value, sentinel->next);
    sentinel->next = node;
}
void IntList::push_back(int data) {
    // TODO:
}
void IntList::pop_front() {
    assert(!empty());
    Node *node = sentinel->next;
    sentinel->next = node->next;
    delete node;
}
void IntList::print(std::ostream &os) const {
    for (Node *node = sentinel->next; node; node = node->next) {
        os << node->data << " ";
    }
}

void IntList::push_all(const IntList &other) {
    for (Node *node = other.sentinel->next; node; node = node->next) {
        push_back(node->data);
    }
}
void IntList::pop_all() {
    while (!empty()) {
        pop_front();
    }
    delete sentinel;
}

int &IntList::Iterator::operator*() const {
    assert(ptr);
    return ptr->data;
}
IntList::Iterator &IntList::Iterator::operator++() {
    assert(ptr);
    ptr = ptr->next;
    return *this;
}
IntList::Iterator IntList::Iterator::operator++(int) {
    assert(ptr);
    Iterator tmp = *this;
    ptr = ptr->next;
    return tmp;
}
bool IntList::Iterator::operator==(Iterator rhs) const {
    return ptr == rhs.ptr;
}
bool IntList::Iterator::operator!=(Iterator rhs) const {
    return ptr != rhs.ptr;
}