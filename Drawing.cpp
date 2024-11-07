#include <iostream>
#include "Drawing.h"
#include "ListArray.h"

Drawing::Drawing(){
	shapes = new ListArray<Shape*>();
}

Drawing::~Drawing(){
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape){
	shapes->append(shape);
}

//Executem tots els prints de Shape
void Drawing::print_all() {
	for (int i = 0; i < shapes->size(); ++i){
		shapes->get(i)->print();
	}
}

double Drawing::get_area_all_circles(){

	//Declarem la variable que ens tornarà l'area total dels cercles
	double total_area = 0.0;


	//Obtenim tots els elements de Shape
	for (int i = 0; i < shapes->size(); ++i){
		Shape* shape = shapes->get(i);

		//Verifiquem si el objecte es de tipus Circle utilitzant dynamic cast
		Circle* circle = dynamic_cast<Circle*>(shape);
		//Sumem area en cas de ser circle
		if (circle != nullptr){
			total_area += circle->area();
		}
	}

	return total_area;
}

void Drawing::move_squares(double incX, double incY){

	//Obtenim tots els elements de Shape
	for (int i = 0; i< shapes->size(); ++i){
		Shape* shape = shapes->get(i);

		//Verifiquem que l'objecte és de tipus Square utilitzant dynamic_cast
		Square* square = dynamic_cast<Square*>(shape);

		//Apliquem els offsets en cas de ser quadrats
		if (square != nullptr){
			square->translate(incX, incY);
		}
	}
}
