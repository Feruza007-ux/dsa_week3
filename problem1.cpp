#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long arraySum(int A[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum +=A[i];
    }
    return sum;
}


int main() {
    srand(time(0));

    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int numSizes = 5;
    int runs =5;

    cout<<"Average time(microseconds): "<<endl;
    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];

        int* A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 1000;
        }

        long long totalTime = 0;
        long long result = 0;
        for (int r = 0; r<runs; r++) {
            auto start = high_resolution_clock::now();
            result = arraySum(A, n);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            totalTime += duration.count();
        }

        double average = (double)totalTime / runs;
        cout<<n << "\t"<<average<< "\t(sum = " << result << ")"<<endl;

        delete [] A;
    }
    return 0;


}