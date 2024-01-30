#include <stdio.h>
#include <time.h>

// Recursive Fibonacci
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Iterative Fibonacci
int fib_iterative(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0) return a;
    for (i = 2; i <= n; i++) {
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
    clock_t start, end;
    double cpu_time_used;
    int n, result;
    FILE *outputFile;

    // Open the file for writing
    outputFile = fopen("data.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (n = 1; n <= 50; n++) {
        // Measure Recursive Fibonacci
        start = clock();
        result = fib_recursive(n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(outputFile, "%d, %f, ", n, cpu_time_used * 1000);

        // Measure Iterative Fibonacci
        start = clock();
        result = fib_iterative(n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(outputFile, "%f, ", cpu_time_used * 1000);

        // Measure Recursive Sum of Cubes
        start = clock();
        result = sum_of_cubes_recursive(n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(outputFile, "%f, ", cpu_time_used * 1000);

        // Measure Iterative Sum of Cubes
        start = clock();
        result = sum_of_cubes_iterative(n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(outputFile, "%f\n", cpu_time_used * 1000);
    }

    // Close the file
    fclose(outputFile);

    return 0;
}