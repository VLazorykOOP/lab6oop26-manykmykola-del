#include <iostream>
using namespace std;
class Figure {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void print() = 0;
    virtual ~Figure() {}
};
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() override {
        return 3.14 * radius * radius;
    }
    double perimeter() override {
        return 2 * 3.14 * radius;
    }
    void print() override {

        cout << "Circle" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};
class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    double area() override {
        return width * height;
    }
    double perimeter() override {
        return 2 * (width + height);
    }
    void print() override {
        cout << "Rectangle" << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};
class Trapezoid : public Figure {
private:
    double a, b, c, d, h;
public:
    Trapezoid(double x1,
              double x2,
              double x3,
              double x4,
              double height) {
        a = x1;
        b = x2;
        c = x3;
        d = x4;
        h = height;
    }
    double area() override {
        return ((a + b) * h) / 2;
    }

    double perimeter() override {
        return a + b + c + d;
    }
    void print() override {
        cout << "Trapezoid" << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};
int main() {
    Figure* figures[3];
    figures[0] = new Circle(5);
    figures[1] = new Rectangle(4, 6);
    figures[2] = new Trapezoid(5, 7, 4, 4, 3);
    for (int i = 0; i < 3; i++) {
       figures[i]->print();
        cout << "------------------" << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete figures[i];
    }
    return 0;
}
