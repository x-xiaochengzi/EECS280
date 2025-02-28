#ifndef SHAPES_H
#define SHAPES_H

#include "Canvas.h"

////////////////////////// vvvvv DO NOT CHANGE vvvvv //////////////////////////

/*********************************** SHAPE ***********************************/

class Shape {
  public:
    // EFFECTS: creates a Shape with initial position (0,0)
    Shape() : x_pos(0), y_pos(0) {}

    // EFFECTS: returns the area of this Shape
    virtual double area() const = 0;

    // MODIFIES: *canvas
    // EFFECTS: draws this shape onto canvas at its current position
    virtual void draw(Canvas *canvas) const = 0;

    // MODIFIES: *this
    // EFFECTS: sets the position of this shape
    void set_position(double x_pos_in, double y_pos_in) {
        x_pos = x_pos_in;
        y_pos = y_pos_in;
    }

    double get_x_pos() const { return x_pos; }
    double get_y_pos() const { return y_pos; }

  private:
    // Represents the position of this shape
    double x_pos, y_pos;
};

/********************************** ELLIPSE **********************************/

class Ellipse : public Shape {
  public:
    // REQUIRES: x_rad_in, y_rad_in are non-negative
    // EFFECTS: creates an Ellipse with given x and y radii at position (0,0)
    Ellipse(double x_rad_in, double y_rad_in);

    // EFFECTS: returns the area of this Ellipse
    virtual double area() const override;

    // MODIFIES: *canvas
    // EFFECTS: draws this shape onto canvas
    virtual void draw(Canvas *canvas) const override;

  private:
    // Radii of the ellipse
    double x_rad, y_rad;
};

////////////////////////// ^^^^^ DO NOT CHANGE ^^^^^ //////////////////////////

/********************************** CIRCLE ***********************************/
class Circle : public Ellipse {
  public:
    // REQUIRES: rad_in >= 0
    // EFFECTS: create a circle with given raduis
    Circle(double rad_in);
};

/********************************* RECTANGLE *********************************/

class Rectangle : public Shape {
  public:
    // REQUIRES: width_in >= 0 && height_in >= 0
    // EFFECTS: create a rectangel with given width and height
    Rectangle(double width_in, double height_in);
    // EFFECTS: returns the area of this rectangle
    virtual double area() const override;
    // MODIFIES: *canvas
    // EFFECTS: draws this shape onto canvas
    virtual void draw(Canvas *canvas) const override;

  private:
    double width, height;
};

#endif /* SHAPES_H */
