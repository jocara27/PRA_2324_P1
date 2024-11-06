#include <ostream>
#include "Point2D.h"
#include <cmath>

Point2D::Point2D(double x, double y){
        this->x = x;
        this->y = y;
}

//Traem la distancia euclidiana dels dos punts
double Point2D::distance(const Point2D &a, const Point2D &b){
       double d = 0;
       d = sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
       return d;
}

bool operator==(const Point2D &a, const Point2D &b){
        bool igualtat = (a.x == b.x && a.y == b.y);
        return igualtat;
}

bool operator!=(const Point2D &a, const Point2D &b){
        bool desigualtat = !(a==b);
        return desigualtat;
}
std::ostream& operator<<(std::ostream &out, const Point2D &p){
        out << "Punt: (" << p.x << "," << p.y << ")";
        return out;
}

