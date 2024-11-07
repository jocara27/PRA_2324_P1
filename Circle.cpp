#include <iostream>
#include "Circle.h"
#include <cmath>

Circle::Circle(){
	this-> radius = 1;
	this-> center = 0,0;
}

Circle::Circle(std::string color, Point2D center, double radius){
	this->color = color;
	this->center = center;
	this->radius = radius;
}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	this->center = p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	this->radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "Cercle: [Color: " << c.color << ", Centre: (" <<c.get_center().x << ", " << c.get_center().y << ")" << ", Radi: " << c.get_radius() << ", Area: " << c.area() << ", Perímetre: " << c.perimeter() << "]";
	return out;
}

double Circle::area() const{
	double area = M_PI * pow(get_radius(),2);
	return area;
}

double Circle::perimeter() const{
	double perimeter = 2 * M_PI * get_radius();
	return perimeter;
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
}

void Circle::print() {
    std::cout << "Cercle==> [Color: " << color << "; Radi: " << radius << "; Centre: (" << center.x << ", " << center.y << ")]" << std::endl;
}
