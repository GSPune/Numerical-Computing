#include <bits/stdc++.h>
using namespace std;
#include "RF.hpp"
#define pi 3.14159265

bisection::bisection()
{
    a = b = 0.0;
    //TOL = pow(10,-2);
}

void bisection::find_interval()
{
    double x1 = 0,x2 = 1;
    while(x1 > -500 && x2 < 500)
    {
        if (f(x1) * f(x2) < 0)
        {
            a = x1;
            b = x2;
            cout << "Bracketting Interval found:(" <<a<<", "<<b<<")\n";
            return;
        }
        else{
            x1--;x2++;
        }
    }

    cout << " NO Valid Bracketing Interval found!" <<endl;
    exit(1);
}

void bisection::get_interval(double x1,double x2)
{
    if (f(x1) * f(x2) < 0)
    {
        a = x1;
        b = x2;
        return;
    }
    //else
    cout << "Invalid Bracketing Interval" <<endl;
    exit(1);
}

double bisection::f(double x)
{
    //return (2*pow(x,2) - 1);
    //return (4*pow(x,3)-3*x);
    //return sin(x * (pi/2)) - x;
    //return (pow(x,2)-6*x+6);
    return (pow(x,2)-5*x+3);
}

void bisection::solve()
{
     double m,c;
     do
    {
        m = (a+b)/2;
        if (f(m) == 0)
        {
            cout << "The approximated root via Bisection Method is " << m << "!" << endl;
            exit(1);
        }

        c = f(b) - f(m);
        if (f(m)*f(a) < 0)
        {
            b = m;
        }
        else{
            a = m;
        }
    } while(fabs(c) > TOL);

    this->root = m;
    cout << "The approximated root via Bisection Method is " << m << "!" << endl;
}

void bisection::displayRoot(){
    cout << "The approximated root via Bisection Method is " << root << "!" << endl;
}
