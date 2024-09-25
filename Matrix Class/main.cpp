using namespace std;
#include "include/MatrixClass.hpp"
// #include "gnuplot-iostream.h"
//Testing ground!
int main(void)
{
    // string L,R;
    // L = "TextFiles(Input Matrices)//testLU_L4.txt";
    // R = "TextFiles(Input Matrices)//testLU_R4.txt";
    // L = "TextFiles(Input Matrices)//testC_L3.txt";
    // R = "TextFiles(Input Matrices)//testC_R3.txt";
    // Matrix Aug;
    // Aug.readMatrixViaFiles(L,R);
    // Aug.solveSystemViaLU();
    // Aug.readMatrixViaFiles(L,R);
    // Aug.solveSystemViaCholesky();
    // Aug.guassianElimination();
    
    // Aug.guassianElimination();

    // Matrix T,U;
    // T.readMatrixFromUser();
    // T.display();
    // U.readMatrixFromUser();
    // U.display();
    // Matrix R(T-U);
    // R.display();
    // double d = T.determinant();
    // cout << "Determinant is: " << d << endl;

    // /T.inverse();
    // Matrix Inv(T.inverse());
    // Inv.display();
    // T.display();
    // vector<Matrix> ans;
    // ans = T.choleskyDecomposition();
    // ans[0].display();
    // ans[1].display();

    Matrix T;
    string Lt,Rt;
    Lt = "TextFiles(Input Matrices)//L_3.txt";
    Rt = "TextFiles(Input Matrices)//R_4.txt";
    T.readMatrixViaFiles(Lt,Rt);
    T.display();
    T.guassJacobi();
    // T.guassSeidel();
    
    // T.guassianElimination();

    // T.readMatrixViaFiles(L,R);
    // T.readMatrixFromUser();
    // vector<Matrix> ans;
    // ans = T.lowerUpperDecomposition();
    // ans[0].display();
    // ans[1].display();
    return 0;
}