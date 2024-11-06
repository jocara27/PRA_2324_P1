#include <string>
#include "Point2D.h"
#include "Shape.h"

//Constructor per defecte que crea una figura roja
Shape::Shape(){
	this->color = "red";	
}

//Crea una figura del color específic
Shape::Shape(std::string color){
	this->color = color;

	if(color != "red" && color!= "green" && color != "blue"){
		throw std::invalid_argument("El color introduït no és apte");
	}
}

//Obtenim el balor de color
std::string Shape::get_color() const{
	return color;
}

//Posem valor a color
void Shape::set_color(std::string c){
	if(c != "red" && c!= "green" && c != "blue"){
                throw std::invalid_argument("El color introduït no és apte");
	}
	this->color = c;
}

