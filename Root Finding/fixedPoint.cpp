#include "RF.hpp"

double fixedPoint::f(double x){
    return (pow(x,3)+3)/5;
}

void fixedPoint::solve(){
    double x0 = 1,prev;
    do{
        prev = x0;
        x0 = f(x0);
    }while(fabs(x0-prev) > TOL);

    this->root = x0;
}

void fixedPoint::displayFixedPoint(){
    cout << "The approximate fixed point is " << root << "!" << endl;
}