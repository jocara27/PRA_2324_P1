#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"


//Creem la condició que retorna TRUE si els vertexs formen un rectangle
bool Rectangle::check(Point2D* vertices) {
    return (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3]) && Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[3], vertices[0]));
}

//Constructor de rectangle amb valors predeterminats
Rectangle::Rectangle(){

	vs = new Point2D[N_VERTICES];
	this->color = "red";
	vs[0] = Point2D(-1,0.5);
	vs[1] = Point2D(1,0.5);
	vs[2] = Point2D(1,-0.5);
	vs[2] = Point2D(-1,-0.5);
}

//Constructor de rectangle amb valor de l'usuari
Rectangle::Rectangle(std::string color, Point2D* vertices){
	
	//Si els vertexs no formen un rectangle llancem una excepció
	if(!check(vertices)){
		throw std::invalid_argument("Els vertexs no formen un rectangle");
	}
	this->color = color;
	vs = new Point2D[N_VERTICES];
	vs[0] = vertices[0];
	vs[1] = vertices[1];
	vs[2] = vertices[2];
	vs[3] = vertices[3];
}

//Constructor de còpia
Rectangle::Rectangle(const Rectangle &r){
	this->color = color;
	vs = new Point2D[N_VERTICES];

	vs[0] = r.vs[0];
	vs[1] = r.vs[1];
	vs[2] = r.vs[2];
	vs[3] = r.vs[3];
}

//Destrucor, lliberem memòria
Rectangle::~Rectangle(){
	delete[] vs;
}

//Tornem el Point2D
Point2D Rectangle::get_vertex(int ind) const {

	//Comprovem si l'index està dins del rang
	if (ind < 0 || ind >= N_VERTICES) {
        	throw std::out_of_range("Busques un idex massa al o massa menut");
	}
	return vs[ind];
}

//Sobrecarreguem l'operador i tornem l'element que es situa en ind
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind); // Llama a get_vertex para reutilizar la validación
}

//Modifiquem els vertexs
void Rectangle::set_vertices(Point2D* vertices) {

	//Comprovem si els vertexs formen un rectangle
	if (!check(vertices)) {
        	throw std::invalid_argument("Els vertexs no formen un rectangle");
	}
	// Si els vertecxs son vàlids, els assignem a vs
	// Provem un bucle for (per fer-ho diferent al constructor)
	for (int i = 0; i < N_VERTICES; ++i) {
		this->vs[i] = vertices[i];
	}
}

//Assignació de la còpia
Rectangle& Rectangle::operator=(const Rectangle &r){

	//Verifiquem la seua autoassignació
	if (this != &r){
		delete[] vs;
		vs = new Point2D[N_VERTICES];

		for(int i = 0; i < N_VERTICES; ++i){
			vs[i] = r.vs[i];
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "Rectangle: [Color: " << r.color << "; v0: " << r.vs[0] << "; v1: " << r.vs[1] << "; v2: " << r.vs[2] << "; v3: " << r.vs[3]; 
	return out;
}




//HERETATS
double Rectangle::area() const{
	return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[0], vs[3]);
}

double Rectangle::perimeter() const{
	return (2 * Point2D::distance(vs[0], vs[1])) + (2 * Point2D::distance(vs[0], vs[3]));
}

void Rectangle::translate(double incX, double incY){

	//Creem un bucle for per a traslladar tots els vertexs
	for(int i = 0; i < N_VERTICES; ++i){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(){

	std::cout << "Rectangle [Color: " << color << ", v0: " << vs[0] << ", v1: " << vs[1] << ", v2: " << vs[2] << ", v3: " << vs[3] << "]" << std::endl;
}
