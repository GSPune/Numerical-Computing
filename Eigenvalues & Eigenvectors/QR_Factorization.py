import numpy as np
from numpy.linalg import qr

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
    printMatrix(Q)
    printMatrix(R)

    Product = Q @ R
    printMatrix(Product)