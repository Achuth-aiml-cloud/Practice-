#include <iostream>
#include <chrono>

// Recursive Fibonacci
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci
int fib_iterative(int n) {
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
int sum_of_cubes_recursive(int n) {
    if (n <= 0) return 0;
    return n*n*n + sum_of_cubes_recursive(n - 1);
}

// Iterative Sum of Cubes
int sum_of_cubes_iterative(int n) {
    return n * n * (n + 1) * (n + 1) / 4;
}

int main() {
    for (int n = 1; n <= 50; n++) {
        // Measure Recursive Fibonacci
        auto start = std::chrono::high_resolution_clock::now();
        int result = fib_recursive(n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Recursive Fibonacci of " << n << ": " << result << ", Time: " << elapsed.count() << " seconds\n";

        // Measure Iterative Fibonacci
        start = std::chrono::high_resolution_clock::now();
        result = fib_iterative(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Iterative Fibonacci of " << n << ": " << result << ", Time: " << elapsed.count() << " seconds\n";

        // Measure Recursive Sum of Cubes
        start = std::chrono::high_resolution_clock::now();
        result = sum_of_cubes_recursive(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Recursive Sum of Cubes of " << n << ": " << result << ", Time: " << elapsed.count() << " seconds\n";

        // Measure Iterative Sum of Cubes
        start = std::chrono::high_resolution_clock::now();
        result = sum_of_cubes_iterative(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        std::cout << "Iterative Sum of Cubes of " << n << ": " << result << ", Time: " << elapsed.count() << " seconds\n";
    }

    return 0;
}
