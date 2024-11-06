#include <iostream>
#include "Square.h"
#include "Point2D.h"

//Creem un Check igual que en la classe Rectangle, així sabem si estem manipulant un quadrat
bool Square::check(Point2D* vertices){
	return (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[2], vertices[3]) == Point2D::distance(vertices[3], vertices[0]));
}

//Creem un quadrat predeterminat
Square::Square(){
	this->color="red";
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1,1);
	vs[1] = Point2D(1,1);
	vs[2] = Point2D(1,-1);
	vs[3] = Point2D(-1,-1);
}

//Creem un quadrat amb les dades de l'usuari (en cas de ser coherents)
Square::Square(std::string color, Point2D* vertices){

	//Comprovem si els vertexs formen un quadrat
	if(!check(vertices)){
		throw std::invalid_argument("Els vertexs insertats no formen un quadrat");
	}

	this->color = color;
	vs = new Point2D[N_VERTICES];
	vs[0] = vertices[0];
	vs[1] = vertices[1];
        vs[2] = vertices[2];
        vs[3] = vertices[3];
}

//Funció que modifica els vertexs
void Square::set_vertices(Point2D* vertices){

	//Comprovem que els vertexs formen un quadrat
	if(!check(vertices)){
                throw std::invalid_argument("Els vertexs insertats no formen un quadrat");
        }

	for(int i = 0; i < N_VERTICES; ++i){
		this->vs[i] = vertices[i];
	}
}

std::ostream& operator<<(std::ostream &out, const Square &square){
        out << "Quadrat: [Color: " << square.color << "; v0: " << square.vs[0] << "; v1: " << square.vs[1] << "; v2: " << square.vs[2] << "; v3: " << square.vs[3];
        return out;
}

//HERETATS
double Square::area() const{
        return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[0], vs[3]);
}

double Square::perimeter() const{
        return (2 * Point2D::distance(vs[0], vs[1])) + (2 * Point2D::distance(vs[0], vs[3]));
}

void Square::translate(double incX, double incY){

        //Creem un bucle for per a traslladar tots els vertexs
        for(int i = 0; i < N_VERTICES; ++i){
                vs[i].x += incX;
                vs[i].y += incY;
        }
}

void Rectangle::print(){

        std::cout << "Quadrat [Color: " << color << ", v0: " << vs[0] << ", v1: " << vs[1] << ", v2: " << vs[2] << ", v3: " << vs[3] << "]" << std::endl;
}

