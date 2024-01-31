#include <iostream>
#include <chrono>
#include <fstream>


// Recursive Fibonacci
int fibRecursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci
int fibIterative(int n) {
    int a = 0, b = 1, c;
    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}

// Recursive Sum of Cubes
int sumOfCubesRecursive(int n) {
    if (n <= 0) return 0;
    return n*n*n + sum_of_cubes_recursive(n - 1);
}


int sumOfCubesIterative(int n) {
    return n * n * (n + 1) * (n + 1) / 4;
}

int main() {
    std::ofstream outputFile("timing_data.txt");

    for (int n = 1; n <= 50; n++) {
        std::chrono::duration<double> elapsed;
        int result;

        // Time for Recursive Fibonacci
        auto start = std::chrono::high_resolution_clock::now();
        result = fibRecursive(n);
        auto end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        outputFile << n << ", " << elapsed.count() << ", ";

        // Time for  Iterative Fibonacci
        start = std::chrono::high_resolution_clock::now();
        result = fibIterative(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        outputFile << elapsed.count() << ", ";

        // Time for Recursive Sum of Cubes
        start = std::chrono::high_resolution_clock::now();
        result = sumOfCubesRecursive(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        outputFile << elapsed.count() << ", ";

        // Time for Iterative Sum of Cubes
        start = std::chrono::high_resolution_clock::now();
        result = sumOfCubesIterative(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        outputFile << elapsed.count();

        outputFile << std::endl;
    }

    outputFile.close();
    return 0;
}
