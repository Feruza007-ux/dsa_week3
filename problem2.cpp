#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
using namespace std;

int linearSearch(int A[], int n, int key) {
    for (int i =0; i<n;i++) {
        if (A[i]== key) return i;
    }
    return -1;
}

double timeSearch(int A[], int n, int key, int runs) {
    linearSearch(A, n, key);

    long long totalTime = 0;
    for (int i = 0; i < runs; i++) {
        auto start = high_resolution_clock::now();
        linearSearch(A, n, key);
        auto end = high_resolution_clock::now();

        totalTime += duration_cast<nanoseconds>(end - start).count();
    }
    return (double)totalTime / runs;
}


int main() {
    int sizes[] = {1000, 5000,10000,50000, 100000};
    int numSizes = 5;
    int runs = 5;

    cout << "n\tBest(ns)\tAvg(ns)\t\tWorst(ns)" << endl;

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        int* A = new int[n];
        for (int j = 0; j < n; j++) {
            A[j] = j;
        }

        double best = timeSearch(A, n, A[0], runs);
        double avg = timeSearch(A, n , A[n/2], runs);
        double worst = timeSearch(A, n , -999999, runs);

        cout << n << "\t"<< best << "\t\t" << avg << "\t\t" << worst << endl;
        delete [] A;
    }
    return 0;

}