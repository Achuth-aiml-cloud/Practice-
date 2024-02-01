#include <stdio.h>
#include <time.h>
int fibonacciRec(int num) {
    if (num <= 1) return num;
    return fibonacciRec(num - 1) + fibonacciRec(num - 2);
}
int fibonacciIter(int num) {
    int first = 0, second = 1, next, idx;
    if (num == 0) return first;
    for (idx = 2; idx <= num; idx++) {
       next = first + second;
       first = second;
       second = next;
    }
    return second;
}
int cubesSumRec(int num) {
    if (num <= 0) return 0;
    return num*num*num + cubesSumRec(num - 1);
}
int cubesSumIter(int num) {
    return num * num * (num + 1) * (num + 1) / 4;
}
int main() {
    clock_t begin, finish;
    long cpu_time_us;
    int val, output;
    FILE *resultfile;

    resultfile = fopen("results.txt", "w");
    if (resultfile == NULL) {
        printf("Unable to open fil\n");
        return 1;
    }

    for (val = 1; val <= 50; val++) {
        
        begin = clock();
        output = fibonacciRec(val);
        finish = clock();
        cpu_time_us = ((finish - begin) * 1000000L) / CLOCKS_PER_SEC;
        fprintf(resultfile, "%d, %ld, ", val, cpu_time_us);
        

        begin = clock();
        output = fibonacciIter(val);
        finish = clock();
        cpu_time_us = ((finish - begin) * 1000000L) / CLOCKS_PER_SEC;
        fprintf(resultfile, "%ld, ", cpu_time_us);
        

        begin = clock();
        output = cubesSumRec(val);
        finish = clock();
        cpu_time_us = ((finish - begin) * 1000000L) / CLOCKS_PER_SEC;
        fprintf(resultfile, "%ld, ", cpu_time_us);
        

        begin = clock();
        output = cubesSumIter(val);
        finish = clock();
        cpu_time_us = ((finish - begin) * 1000000L) / CLOCKS_PER_SEC;
        fprintf(resultfile, "%ld\n", cpu_time_us);
       
    }

    fclose(resultfile);

    return 0;
}
