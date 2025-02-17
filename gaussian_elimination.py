import random
import time
import sys

def gaussian_elimination(A):
    """
    Perform naive Gaussian elimination in-place on matrix A of size n x n.
    This code does NOT do partial pivoting and does no checks for singular matrices.
    """
    n = len(A)
    for i in range(n):
        # Scale the pivot row (row i) so that the pivot element becomes 1
        pivot = A[i][i]
        for k in range(i, n):
            A[i][k] /= pivot

        # Eliminate below pivot
        for j in range(i+1, n):
            factor = A[j][i]
            for k in range(i, n):
                A[j][k] -= factor * A[i][k]

def main():
    """
    Usage: python gaussian_elimination.py <n>
      - n is the dimension of the matrix (n x n). Default = 2000.
    """
    if len(sys.argv) > 1:
        n = int(sys.argv[1])
    else:
        n = 2000

    # Generate a random n x n matrix (float entries)
    print(f"Generating a {n}x{n} matrix...")
    A = [[random.random() for _ in range(n)] for _ in range(n)]

    print("Starting Gaussian elimination...")
    start_time = time.time()
    gaussian_elimination(A)
    end_time = time.time()

    elapsed = end_time - start_time
    print(f"Time taken for {n}x{n} Gaussian elimination: {elapsed:.2f} seconds")

if __name__ == "__main__":
    main()
