import numpy as np
from numpy.linalg import qr,eig

def qrFactorization(A):
    a = np.array(A)
    q, r = qr(a)

    return q, r

def printMatrix(B):

    r = len(B)
    c = len(B[0])
    for i in range(r):
        for j in range(c):
            print(f"{round(B[i][j],3)} ", end='')
        print()
    print()

if __name__ == "__main__":
    r = int(input("Enter the number of rows: "))
    c = int(input("Enter the number of columns: "))
    
    A = []
    print("Enter the elements row by row:")
    for i in range(r):
        row = list(map(float, input().split()))
        A.append(row)
    print()
    Q, R = qrFactorization(A)

    # print("Q:", Q)
    print("Matrix Q")
    printMatrix(Q)
    print("Matrix R")
    printMatrix(R)

    Product = Q @ R
    print("Product of Q and R::")
    printMatrix(Product)

    w,v=eig(Product)
    print("Eigen-value:", w, "\n")
    print("Eigen-vector:\n", v)

    # print("Eigen-value:", printMatrix(w.tolist()))
    # print("Eigen-vector", printMatrix(v.tolist()))