#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
	private:
		static bool check(Point2D* vertices);
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);

		//HERETATS DE SHAPE
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY);
		void print() override;
		

		//HERETATS DE RECTANGLE
		void set_vertices(Point2D* vertices) override;

};
#endif
