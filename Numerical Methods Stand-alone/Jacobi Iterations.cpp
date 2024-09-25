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
    double a,b,c,x0,y0,z0;
    x0 = fx(0.0,0.0),y0 = fy(0.0,0.0),z0 = fz(0.0,0.0);
    cout << "Values of x, y, z are: " << x0 << ", " << y0 << ", "<< z0 << " \n";
    for (int i =0; i < 10; i++){
        a = fx(y0,z0);//x
        b = fy(x0,z0);//y
        c = fz(x0,y0);//z
        cout << "Values of x, y, z are: " << a << ", " << b << ", "<< c << " \n";
        x0 = a;y0 = b;z0 =c;
    }
    return 0;
}