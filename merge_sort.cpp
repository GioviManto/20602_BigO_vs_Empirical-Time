#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>  // For std::swap, if needed
#include <chrono>

using namespace std;

// --- MERGE SORT IMPLEMENTATION ---
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while(i < n1) {
        arr[k++] = L[i++];
    }
    while(j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(int argc, char** argv) {
    // Default array size is 1e6 if no argument is provided
    long long n = 1000000;
    if(argc > 1) {
        n = atoll(argv[1]);
    }

    cout << "Generating array of size " << n << " ..." << endl;
    srand((unsigned) time(NULL));
    vector<int> arr(n);
    for(long long i = 0; i < n; i++) {
        arr[i] = rand(); // random int
    }

    cout << "Starting merge sort..." << endl;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Time taken to sort " << n << " elements: " 
         << diff.count() << " seconds" << endl;

    // Optional: verify that arr is sorted
    // for(int i = 0; i < n - 1; i++){
    //     if(arr[i] > arr[i+1]){
    //         cerr << "Array not sorted!" << endl;
    //         break;
    //     }
    // }

    return 0;
}
