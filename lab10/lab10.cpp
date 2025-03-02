#include "lab10.h"
#include <iostream>

using namespace std;

/********************************** Functors **********************************/

// EFFECTS: returns whether a's name is before b's (alphabetically)
bool CompareName::operator()(const Person &a, const Person &b) const {
    return a.get_name() < b.get_name();
}

// EFFECTS: returns whether a is younger than b
bool CompareAge::operator()(const Person &a, const Person &b) const {
    return a.get_age() < b.get_age();
}

// Predicate IsAgeN
class IsAgeN {
  public:
    IsAgeN(int age_in) : age(age_in) {
    }
    bool operator()(const Person &a) const {
        return a.get_age() == this->age;
    }

  private:
    int age; // TASK 2a - UNCOMMENT THIS LINE
};

/****************************** Helper Functions ******************************/

// REQUIRES: arr points to an array of size n > 0
// EFFECTS:  returns a pointer to the maximum person in arr according to comp
template <typename Comp>
const Person *find_max(const Person *arr, int n, Comp comp) {
    const Person *max_person = arr;
    for (int i = 1; i < n; i++) {
        if (comp(*max_person, arr[i])) {
            max_person = arr + i;
        }
    }

    return max_person;
}

// REQUIRES: arr points to an array of size n > 0
// EFFECTS:  prints the name and age of every person in arr for which pred returns true
// Print in the form: <Person Name>, <Person Age><newline>
template <typename Predicate>
void print_if(const Person *arr, int n, Predicate pred) {
    for (int i = 0; i < n; ++i) {
        if (pred(arr[i])) {
            cout << arr[i].get_name() << ", " << arr[i].get_age() << endl;
        }
    }
}

/******************************* Test Functions *******************************/

// REQUIRES: people points to an array of size num_people > 0
// EFFECTS:  returns a pointer to the last person alphabetically in people
const Person *find_last_person(const Person *people, int num_people) {
    return find_max(people, num_people, CompareName());
}

// REQUIRES: people points to an array of size num_people > 0
// EFFECTS:  returns a pointer to the oldest person in people
const Person *find_oldest_person(const Person *people, int num_people) {
    return find_max(people, num_people, CompareAge());
}

// REQUIRES: people points to an array of size num_people > 0
// EFFECTS:  prints the name of every person in people whose age is n
void print_people_with_age_n(const Person *people, int num_people, int n) {
    print_if(people, num_people, IsAgeN(n));
}
