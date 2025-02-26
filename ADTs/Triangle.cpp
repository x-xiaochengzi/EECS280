//
// Created by xzc on 2025/2/27.
//

#include "Triangle.h"
Triangle::Triangle()
    :a(1), b(1), c(1) {}

Triangle::Triangle(double a, double b, double c)
    :a(a), b(b), c(c) {}

Triangle::Triangle(double side)
    :Triangle(side, side, side) {}

double Triangle::perimeter() const {
    return this->a + this->b + this->c;
}

void Triangle::scale(int factor) {
    this->a *= factor;
    this->b *= factor;
    this->c *= factor;
}



