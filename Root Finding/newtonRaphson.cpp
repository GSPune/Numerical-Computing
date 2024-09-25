#include "RF.hpp"

double newtonRaphson::f(double x){
    // return pow(x,3)-2*x-5;
    return pow((x-2),2);
}

double newtonRaphson::f_dash(double x){
    return 2*(x-2);
    // return 3*pow(x,2)-2;
}

bool newtonRaphson::check_guess(double guess){
    //|| floor(f_dash(guess)) == 0
    if(f_dash(guess) == 0)
        return false;
    else
        return true;
}

void newtonRaphson::solve(){
    double x0 = 0;
    double prev = 0;
    int iterations = 0;
    double critical_point = 2;//sqrt(2/3);
    // if (!check_guess(x0)){
    //     cout << "The guess will cause numerical instability..needs to be changed!!!" << endl;
    //     exit(1);
    // }
    do{
        prev = x0;
        if (x0 == critical_point){
            //force f_dash(x0) not to go to zero exactly...
            x0 = x0 + TOL;
        }
        // if (isinf(f(x0)/f_dash(x0))){
        //     cout << "Try another guess value..denominator is becoming ZERO due to value of f_dash!" << endl;
        //     exit(1);
        // }
        x0 = x0 - (f(x0)/f_dash(x0));
        iterations++;
    }while(fabs(x0-prev) > TOL);

    this->root = x0;
    cout << "Iterations are :: " << iterations << endl;
}

void newtonRaphson::displayRoot(){
    cout << "The approximated root via Newton Raphson Method is " << root << "!" << endl;
}