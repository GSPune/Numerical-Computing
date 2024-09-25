#include <bits/stdc++.h>
using namespace std;

double fx(double y,double z){
    return (5-2*y-z)/5;
}

double fy(double x,double z){
    //return (9-2*x-4*z);
    return (7-x-z)/(-4);
}

double fz(double x,double y){
    // return (7-x+4*y);
    return (9-2*x-y)/4;
}
int main(){
    double a,b,c;
    a = b = c = 0.0;
    cout << "Values of x, y, z are: " << a << ", " << b << ", "<< c << " \n";
    for (int i =0; i < 10; i++){
        a = fx(b,c);//x
        b = fy(a,c);//y
        c = fz(a,b);//z
        cout << "Values of x, y, z are: " << a << ", " << b << ", "<< c << " \n";
    }
    return 0;
}