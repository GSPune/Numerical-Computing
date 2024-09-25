#include "MatrixClass.hpp"

Matrix Matrix::inverse(){
    Matrix I(this->rows,this->cols);

    for (int i = 0; i < rows; i++){
        I.mat[i][i] = 1;
    }

    //Reduce to upper triangular (echelon)
    for (int i = 0; i < rows; i++){
        double tmp = mat[i][i];
        //Make pivot 1 for row i
        for(int j = 0; j < cols; j++){
            if (mat[i][j] != 0){
                mat[i][j] /= tmp;    
            }
            if (I.mat[i][j] != 0)
                I.mat[i][j] /= tmp;
        }
        
        //Row Transformations for all rows below pivot row i
        for(int k = i+1; k < rows ; k++){
            double t2 = mat[k][i]; //i gives us the current pivot element column
            if (t2 == 0)
                continue;
            for (int p = 0; p < cols; p++){
                //cout << "Row " << k << " - (" << t2 << ")*Row" << i << endl;
                mat[k][p] -= t2*mat[i][p]; 
                I.mat[k][p] -= t2*I.mat[i][p];
            }
        }
    }
    // I.display();

    //Now to reduce the upper triangular part to identity
    //Row Transformations for all rows ABOVE pivot row q
    for (int q = rows-1; q >= 0; q--){
        for (int t = q-1; t >= 0; t--){
            double x = mat[t][q];
            if (x == 0)
                continue;
            for (int c = cols-1; c >= 0; c --){
                mat[t][c] -= x*mat[q][c];
                I.mat[t][c] -= x*I.mat[q][c];
            }
        }
    }

    // display();
    return I;
}