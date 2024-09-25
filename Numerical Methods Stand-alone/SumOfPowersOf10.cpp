#include <bits/stdc++.h>
using namespace std;

double sum(int n, int k){
    double s = 0;
    for (int i = 0; i < pow(10,k);i++){
        s += pow(10,(-1)*n);
    }
    return s;
}

int main(){
    int k,n;
    cin >> n >> k;
    cout << sum(n,k) << endl;
    return 0;
}