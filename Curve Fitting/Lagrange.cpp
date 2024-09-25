#include <bits/stdc++.h>
#include "Point.cpp"
using namespace std;

double numerator(double x,int i,vector<Point> P,double n){
    double result = 1.0;
    for (int j = 0; j < n; j++){
        if (j != i)
            result *= (x-P[j].x);
    }
    return result;
}

double denominator(int i,vector<Point> P,int n){
    double result = 1.0;
    for (int j = 0; j < n; j++){
        if (j != i)
            result *= (P[i].x - P[j].x);
    }
    return result;
}

double lagrangePolynomial(double x,int n,vector<Point> P){
    double res = 0.0;
    for (int i = 0; i < n; i++){
        res += (P[i].y) * (numerator(x,i,P,n)/denominator(i,P,n));
    }
    return res;
}

int main(){
    int n;
    cout << "Enter the total number of points: ";
    cin >> n;
    vector<Point> Data(n);
    cout << "Enter the points one by one: " << endl;
    for (Point &e:Data)
        cin >> e.x >> e.y;

    for (int k = 0; k < n; k++)
        cout << "The value of interpolating polynomial at " << Data[k].x << " is: " 
        << lagrangePolynomial(Data[k].x,n,Data) << endl;

    return 0;
}