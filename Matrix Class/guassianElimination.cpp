#include "MatrixClass.hpp"

void Matrix::guassianElimination(){

    //Steps
    //1. Reduce to Lower Triangular

    for (int i = 0; i < rows; i++){
        double tmp = mat[i][i];
        //Make pivot 1 for row i
        for(int j = 0; j < cols; j++){
            if (mat[i][j] != 0){
            mat[i][j] /= tmp;}
         }
        
        //Row Transformations for all rows below pivot row i
         for(int k = i+1; k < rows ; k++){
            double t2 = mat[k][i];
            if (t2 == 0)
                continue;
            for (int p = i; p < cols; p++){
                //cout << "Row " << k << " - (" << t2 << ")*Row" << i << endl;
                mat[k][p] -= t2*mat[i][p]; 
            }
         }
         //printMatrix(mat,rows,cols);
     }
    cout << "Echelon Form:" << endl;
    // printMatrix(mat,rows,cols);
    display();

    //2. Back Substitution
    //double *ans = new double[cols-2];
    double* ans = new double[cols-2];
    backSubstitution(mat,ans);
    // backSubstitution<double,k>(mat,ans);

    ofstream fout;
    string outf = "Output Matrices//" + to_string(cols-1) + "T_sol.txt";
    fout.open(outf);
    // fout.open("Output Matrices//3_sol.txt");
    for (int k = 0; k < cols - 1; k++){
        fout << ans[k] << "\n";
    }
    fout.close();
    delete[] ans;
}