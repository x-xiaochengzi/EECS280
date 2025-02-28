#include "lab04.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

int main() {

    // TASK 1: Add code to do the following:
    //  - Create a local EmployeeRecord object
    //  - Initialize the EmployeeRecord using EmployeeRecord_init
    //  - Print the EmployeeRecord using EmployeeRecord_print
    EmployeeRecord rec;
    EmployeeRecord_init(&rec, "xzc", "male", 18, 10);
    EmployeeRecord_print(&rec);

    // TASK 2: Add code to do the following:
    //  - Create a Company with the name "eecsSoft"
    //  - Add EXACTLY three Employees to the company, using the Employee
    //    constructor and the Company hire_employee function
    //  - Print the company to cout using the << operator
    Company company("eecsSoft");
    Employee e1("xzc", "male", 18, 1);
    Employee e2("lzy", "female", 18, 1);
    Employee e3("xxx", "male", 18, 1);
    company.hire_employee(e1);
    company.hire_employee(e2);
    company.hire_employee(e3);
    cout << company;

    // TASK 2 - Add code to do the following:
    //  - Promote one employee at the company
    //  - Demote one employee at the company
    //  - Print the company to cout using the << operator
    company.promote_employee("xzc");
    company.demote_employee("xxx");
    cout << company;
}
