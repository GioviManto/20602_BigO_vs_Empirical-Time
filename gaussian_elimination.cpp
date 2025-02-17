#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int main(int argc, char** argv) {
    // Default size is 2000 if no argument is provided
    int n = 2000;
    if(argc > 1) {
        n = atoi(argv[1]);
    }

    cout << "Generating a " << n << "x" << n << " matrix of floats ..." << endl;
    srand((unsigned) time(NULL));

    vector<vector<double> > A(n, vector<double>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = static_cast<double>(rand()) / RAND_MAX; 
        }
    }

    cout << "Starting naive Gaussian elimination..." << endl;
    auto start = chrono::high_resolution_clock::now();

    // -- GAUSSIAN ELIMINATION (NAIVE, NO PIVOTING) --
    for(int i = 0; i < n; i++){
        double pivot = A[i][i];
        // Scale the pivot row
        for(int k = i; k < n; k++){
            A[i][k] /= pivot;
        }
        // Eliminate below pivot
        for(int j = i + 1; j < n; j++){
            double factor = A[j][i];
            for(int k = i; k < n; k++){
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Time taken for " << n << "x" << n << " elimination: " 
         << diff.count() << " seconds" << endl;

    return 0;
}
