#include "shapes.h"
#include <cassert>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

////////////////////////// vvvvv DO NOT CHANGE vvvvv //////////////////////////
/********************************** ELLIPSE **********************************/

Ellipse::Ellipse(double x_rad_in, double y_rad_in)
    : x_rad(x_rad_in), y_rad(y_rad_in) {}

double Ellipse::area() const {
    return PI * x_rad * y_rad;
}

void Ellipse::draw(Canvas *canvas) const {
    // Iterate over every canvas "pixel"
    for (int x = 0; x < Canvas::WIDTH; ++x) {
        for (int y = 0; y < Canvas::HEIGHT; ++y) {

            double x_diff = x - get_x_pos();
            double y_diff = y - get_y_pos();

            // If the ellipse contains the (x,y), such that
            //
            //    (x - x_pos)^2   (y - y_pos)^2
            //    (---------)   + (---------)   <= 1
            //    (  x_rad  )     (  y_rad  )
            //
            // then set the canvas pixel to ON
            if (pow((x_diff / x_rad), 2) + pow((y_diff / y_rad), 2) <= 1) {
                canvas->set_pixel(x, y, true);
            }
        }
    }
}

////////////////////////// ^^^^^ DO NOT CHANGE ^^^^^ //////////////////////////

/********************************** CIRCLE ***********************************/

Circle::Circle(double rad_in) : Ellipse(rad_in, rad_in) {}

/********************************* RECTANGLE *********************************/

Rectangle::Rectangle(double width_in, double height_in)
    : width(width_in), height(height_in) {}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::draw(Canvas *canvas) const {
    // Iterate over every canvas "pixel"
    for (int x = 0; x < Canvas::WIDTH; ++x) {
        for (int y = 0; y < Canvas::HEIGHT; ++y) {
            double x_diff = abs(get_x_pos() - x);
            double y_diff = abs(get_y_pos() - y);
            if (x_diff <= width / 2 && y_diff <= height / 2) {
                canvas->set_pixel(x, y, true);
            }
        }
    }
}
