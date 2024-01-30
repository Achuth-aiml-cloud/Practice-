import matplotlib.pyplot as plt
n_values = []
recursive_fib_times = []
iterative_fib_times = []
recursive_sum_times = []
iterative_sum_times = []

with open('timing_data.txt', 'r') as file:
    for line in file:
        values = line.strip().split(',')
        if len(values) != 5:
            continue  

        n, fib_rec, fib_iter, sum_rec, sum_iter = map(float, values)
        n_values.append(n)
        #converting time into milli-seconds
        recursive_fib_times.append(fib_rec * 1000)  
        iterative_fib_times.append(fib_iter * 1000) 
        recursive_sum_times.append(sum_rec * 1000)  
        iterative_sum_times.append(sum_iter * 1000) 


plt.plot(n_values, recursive_fib_times, label='Recursive Fibonacci', linestyle='--')
plt.plot(n_values, iterative_fib_times, label='Iterative Fibonacci', linestyle=':')
plt.plot(n_values, recursive_sum_times, label='Recursive Sum of Cubes', linestyle='--')
plt.plot(n_values, iterative_sum_times, label='Iterative Sum of Cubes', linestyle=':')

plt.xlabel('Input Value (n)')
plt.ylabel('Time Taken (milliseconds)')
plt.title('Performance')
plt.ylim(0, 0.001)
plt.legend()
plt.show()
plt.savefig("output.png")
