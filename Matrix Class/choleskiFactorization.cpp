#include "MatrixClass.hpp"


double Matrix::getLii(int i, double** L){
    double sum = 0.0;
    for (int k = 0; k < i; k++){
        sum += pow(L[i][k],2);
    }
    return sqrt(mat[i][i] - sum);
}

double Matrix::getLij(int i, int j, double** L){
    double sum = 0.0;
    for (int k = 0; k < j; k++){
        sum += L[i][k]*L[j][k];
    }
    return (mat[i][j] - sum)/L[j][j];
}

vector<Matrix> Matrix::choleskyDecomposition(){
    vector<Matrix> Result;
    Matrix L1(this->rows,this->cols);
    Matrix L2(rows,cols);
    double** L = L1.mat;
    vector<vector<double>> T(rows,vector<double>(cols));
    if(!this->isSymmetric()){
        cout << "Matrix is not symmetric.We can't factorise via Cholesky Method!" <<endl;
        exit(0);
        // return;
    }

    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++){
            //go through each column and also compute separately for diagonal and 
            //lower non-diag elements
            if (j >= i){ //searching in lower triangular part only
                if (i == j)
                    L[j][j] = getLii(j,L);
                else    
                    L[j][i] = getLij(j,i,L);//going colwise
            }
        }
    }

    T = L1.transpose();
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            L2.mat[i][j] = T[i][j];
        }
    }
   Result.push_back(L1);
   Result.push_back(L2);
   return Result; 
}

void Matrix::solveSystemViaCholesky(){
        //---------------------------------------Solving via Choleski Decomposition-----------------------------------------
    //1st Step : Get only the lhs part in form of a matrix
    Matrix C(rows,cols-1);//this->rows
    for (int i = 0; i < C.rows; i++){
        for (int j = 0; j < C.cols; j++){
            C.mat[i][j] = mat[i][j];
        }
    }
    C.display();
    vector<Matrix> ans;
    ans = C.choleskyDecomposition(); // A = LL^t
    double** l = ans[0].mat; 
    double** u = ans[1].mat; 
    cout << "Lower Triangular Matrix::"<<endl;
    ans[0].display();
    cout << "(Transpose) Upper Triangular Matrix::"<<endl;
    ans[1].display();
    
    //Solve LZ=b where Z=L^tX
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
    //Now solve for L^tX=Z
    //Update current object's matrix to L^t -- 2 steps
    for(int j =0; j < cols-1; j++)
        mat[j][cols-1] = Z[j];

    for (int i = 0; i < C.rows; i++){
        for (int j = 0; j < C.cols; j++){
            mat[i][j] = u[i][j];
        }
    }
    // display();
    backSubstitution(mat,X);
    cout << "After backward substitution we have the following answers for X" << endl;
    for (int i =0; i < C.cols;i++){
        cout << X[i] << endl;
    }
    cout << endl;

    delete[] Z;
    delete[] X;
//----------------------------------------Solving via Choleski Decomposition-----------------------------------------
}