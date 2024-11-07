#ifndef DRAWING_H
#define DRAWING_H

#include <ostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "ListArray.h"

class Drawing{
	private:
		List<Shape*>* shapes;
	public:
		Drawing();
		~Drawing();
		void add_front(Shape* shape);
		void add_back(Shape* shape);
		void print_all();
		double get_area_all_circles();
		void move_squares(double incX, double incY);

};
#endif
