//
// Created by xzc on 2025/2/27.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

// Triangle.h
// A class that represents a triangle ADT
class Triangle {
public:
    // EFFECTS: Initializes this to a 1x1x1 triangle.
    Triangle();

    // EFFECTS: Initializes this with the given side lengths.
    Triangle(double a, double b, double c);

    // EFFECTS: Initializes this to be an equilateral triangle with the give side length.
    Triangle(double side);

    // EFFECTS: Returns the perimeter of this triangle.
    double perimeter() const;

    // REQUIRES: s > 0
    // MODIFIES: *this
    // EFFECTS: Scales the sides of this triangle by the factor
    void scale(int factor);

private:
    double a;
    double b;
    double c;
    // INVARIANTS:
    // positive side lengths: a > 0 && b > 0 && c > 0
    // triangle inequality: a + b > c && a + c > b && b + c > a
};

#endif //TRIANGLE_H
