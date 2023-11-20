#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Shape {
  std::string name;
public:
  Shape(std::string name);
  virtual ~Shape();
  std::string description();
  virtual double area() = 0;
};

class Square : public Shape {
 private:
  double width;
 public:
  Square(double width);
  double area();
};

class Rectangle : public Shape {
private:
  double width;
  double height;
public:
  Rectangle(double width, double height);
  double area();
};

class Circle : public Shape {
private:
  double radius;
public:
  Circle(double radius);
  double area();
};

Shape::Shape(std::string name)
{
  this->name = name;
}

Shape::~Shape()
{
}

std::string Shape::description()
{
    std::ostringstream oss;
    oss << name << " has area: " << std::fixed << std::setprecision(2) << area();
    return oss.str();
}

Square::Square(double width) : Shape("Square")
{
  this->width = width;
}

double Square::area()
{
  return width * width;
}

Rectangle::Rectangle(double width, double height) : Shape("Rectangle")
{
  this-> width = width;
  this-> height = height;
}
double Rectangle::area()
{
  return width * height;
}

Circle::Circle(double radius) : Shape("Circle")
{
  this->radius = radius;
}

double Circle::area()
{
  return 3.14 * radius * radius;
}

int main () {
    vector<Shape*> vect;
    
    Shape* rect1 = new Rectangle(10,20);
    vect.push_back(rect1);
    Shape* rect2 = new Rectangle(20,30);
    vect.push_back(rect2);
    Shape* circ1 = new Circle(10);
    vect.push_back(circ1);
    Shape* circ2 = new Circle(20);
    vect.push_back(circ2);
    Shape* sqr1 = new Square(10);
    vect.push_back(sqr1);
    Shape* sqr2 = new Square(20);
    vect.push_back(sqr2);
    
    for (size_t i = 0; i < vect.size(); i++) {
        cout << (vect[i])->description() << endl;

    }

}
