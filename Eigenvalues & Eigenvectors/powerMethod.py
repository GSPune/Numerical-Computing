import numpy as np

# Function to multiply matrix and vector
def productMV(T, x):
    rows = len(T)
    cols = len(T[0])
    res = np.zeros(rows)
    for i in range(rows):
        for j in range(cols):
            res[i] += T[i][j] * x[j]
    return res

# Function to compute the norm of a vector
def norm(y):
    return np.sqrt(sum([i**2 for i in y]))

# Power Method to compute dominant eigenvalue and eigenvector
def powerMethod(T, x, r, c):
    maxIterations = 1000
    count = 0
    res = np.zeros(r)
    xi = np.array(x)
    eigen_new = 0.0
    eigen_prev = 0.0

    while True:
        # Reset eigenvalue variable
        eigen_new = 0.0
        res = productMV(T, xi)

        # Normalize the result vector
        norm1 = norm(res)
        res = res / norm1

        # Update xi to x_(i+1)
        xi = res

        # Compute eigenvalue: x^T * A * x
        intd = productMV(T, res)
        eigen_new = np.dot(intd, res)

        # Check for convergence or maximum iterations
        if abs(eigen_new - eigen_prev) < 0.001 or count > maxIterations:
            break

        eigen_prev = eigen_new
        count += 1

    print("Eigenvalue is ->", eigen_new)
    print("The computed eigenvector is:")
    for rw in res:
        print(rw)

if __name__ == "__main__":
    r = int(input("Enter the number of rows: "))
    c = int(input("Enter the number of columns: "))
    
    A = []
    print("Enter the elements row by row:")
    for i in range(r):
        row = list(map(float, input().split()))
        A.append(row)
    
    # Initial guess for eigenvector
    x = [1 if i == 0 else 0 for i in range(c)]
    # x = [1, 2, 1]
    
    powerMethod(A, x, r, c)
