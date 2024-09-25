#include "Point.hpp"

Point :: Point(){
    x = y = 0.0;
}

Point :: Point(double m, double n){
    x = m;
    y = n;
}

void Point::print(){
    cout << "("<<x<<", "<<y<<")" << endl;
}

double Point::getX(){
    return x;
}

double Point::getY(){
    return y;
}