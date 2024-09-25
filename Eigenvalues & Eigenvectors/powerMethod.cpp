#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)

// Note works for square matrices only..
vector<double> productMV(vector<vector<double>> T,vector<double> x){
    int rows = T.size();
    int cols = T[0].size();
    vector<double> res(rows);
    for(int i =0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            res[i] += T[i][j]*x[j];
        }
    }
    return res;
}

double norm(vector<double> y){
    int s = y.size(), d;
    for (int i = 0; i < s; ++i){
        d += pow(y[i],2);
    }
    return sqrt(d);
}

double powerMethod(vector<vector<double>> T,vector<double> x,int r,int c){
    int maxInterations = 1000, count = 0;
    vector<double> res(r), xi = x;
     double eigen_new = 0.0,eigen_prev = 0.0;
    // for (auto e : res) cout << e << endl;

    while(true){
        //reset eigen_new variable
        eigen_new = 0.0;
        res = productMV(T,xi);

        //update x
        double norm1 = norm(res);
        for(int k = 0; k < c; ++k) {
            res[k] /= norm1;
        }

        //change xi to x_i+1
        xi = res;

        //compute eigenvalue x^t * A * x
        vector<double> intd(r);
        intd = productMV(T,res);
    
        for (int i = 0; i < r; ++i) eigen_new += intd[i]*res[i];
        // cout << "Eigenvalue is -> " << eigen_new << endl;
        
        if (abs(eigen_new-eigen_prev) < 0.001 || count > maxInterations) break;
        eigen_prev = eigen_new;
        count++;
    }
    cout << "Eigenvalue is -> " << eigen_new << endl;
    cout << "The computed eigenvector is :: " << endl;
    for (int rw = 0; rw < r; ++rw){
        cout << res[rw] << endl;
    }
}

int main(){
    int r,c;
    cout << "Enter the number of rows and cols" << endl;
    cin >> r >> c;
    vector<vector<double>> A(r,vector<double>(c));
    cout << "Enter the elements one by one" << endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> A[i][j];
            
        }
    }
    vector<double> x(c);
    //making x = {1,0,0,...}
    FOR(i,0,c) {
        if(i == 0) x[i] = 1;
        else x[i] = 0;
    }
    powerMethod(A,x,r,c);
    return 0;
}


