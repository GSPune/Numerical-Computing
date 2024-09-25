#include "MatrixClass.hpp"

vector<Matrix> Matrix::lowerUpperDecomposition(){
    // vector<Matrix> D(2);
    vector<Matrix> D;
    Matrix M1(this->rows,this->cols);
    Matrix M2(rows,cols);
    //To use operator overloading here
    double **U = M1.mat;
    double **L = M2.mat;
    //Approach -- Crout's Method
    for (int i = 0; i < rows; i++){
        U[i][i] = 1;
    }

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            //Go first across the 1st col of L,then 2nd and so on...
            if (c >= r){
                L[c][r] = computeL(mat,L,U,c,r);
            }
        }
        for (int c = 0;c < cols; c++){
            //Go across 1st row of U,then 2nd and so on...
            if (c > r){
                U[r][c] = computeU(mat,U,L,r,c);
            }
        }
    }
    // M1.display();
    //A deep copy is required..hence a copy constructor is a must!
    D.push_back(M1);
    D.push_back(M2);
    // D.emplace_back(M1);
    return D;
}

double Matrix::computeL(double **mat,double **L,double **U,int row,int col){
    double ans,sum = 0.0;
    ans = mat[row][col];
    for (int k = 0; k < col; k++){
        sum += L[row][k]*U[k][col];
    }
    ans -= sum;
    return ans;
 }

double Matrix::computeU(double **mat,double **U,double **L,int row,int col){
    double ans,sum = 0.0;           
    ans = mat[row][col];
    for (int k = 0; k < row; k++){
        sum += L[row][k]*U[k][col];
    }
    ans -= sum;
    return ans/L[row][row];
}

void Matrix::solveSystemViaLU(){
    //---------------------------------------Solving via LU Decomposition-----------------------------------------
    //1st Step : Get only the lhs part in form of a matrix
    Matrix C(rows,cols-1);//this->rows
    for (int i = 0; i < C.rows; i++){
        for (int j = 0; j < C.cols; j++){
            C.mat[i][j] = mat[i][j];
        }
    }
    vector<Matrix> ans;
    ans = C.lowerUpperDecomposition();
    double** l = ans[1].mat; 
    double** u = ans[0].mat; 
    cout << "Lower Triangular Matrix::"<<endl;
    ans[1].display();
    cout << "Upper Triangular Matrix::"<<endl;
    ans[0].display();
    
    //Solve LZ=b where Z=UX
    double* Z = new double[cols-1];
    double* X = new double[cols-1];
    //Update current matrix to L
    for (int i = 0; i < C.rows; i++){
        for (int j = 0; j < C.cols; j++){
            mat[i][j] = l[i][j];
            // cout<<Aug.mat[i][j]<<" ";
        }
    }

    forwardSubstitution(mat,Z);
    cout << "After forward substitution we have the following values for Z" << endl;
    for (int i =0; i < cols-1; i++){
        cout << Z[i] << endl;
    }
    cout << endl;
    //Now solve for UX=Z
    //Update current object's matrix to U -- 2 steps
    for(int j =0; j < cols-1; j++)
        mat[j][cols-1] = Z[j];

    for (int i = 0; i < C.rows; i++){
        for (int j = 0; j < C.cols; j++){
            mat[i][j] = u[i][j];
        }
    }
    backSubstitution(mat,X);
    cout << "After backward substitution we have the following answers for X" << endl;
    for (int i =0; i < C.cols;i++){
        cout << X[i] << endl;
    }
    cout << endl;
    
    delete[] Z;
    delete[] X;
//----------------------------------------Solving via LU Decomposition-----------------------------------------
}
