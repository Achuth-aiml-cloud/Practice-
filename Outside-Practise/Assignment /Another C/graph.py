import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Initialize the DataFrame
data = {'InputSize': [], 'RecFib': [], 'IterFib': [], 'RecCubes': [], 'IterCubes': []}

# Read and parse the file
with open('results.txt', 'r') as file:
    for line in file:
        inputs, fibrecValue, fibiterValue, sumrecValue, sumiterValue = map(float, line.strip().split(','))
        data['InputSize'].append(inputs)
        data['RecFib'].append(fibrecValue)
        data['IterFib'].append(fibiterValue)
        data['RecCubes'].append(sumrecValue)
        data['IterCubes'].append(sumiterValue)

# Convert to DataFrame
df = pd.DataFrame(data)

# Melt the DataFrame for Seaborn
df_melted = df.melt(id_vars=['InputSize'], var_name='Method', value_name='Time')

# Create the Seaborn plot
sns.set_theme(style="whitegrid")
plt.figure(figsize=(10, 6))
sns.lineplot(data=df_melted, x='InputSize', y='Time', hue='Method', style='Method', markers=True, dashes=False)

# Enhance the plot
plt.xlabel('Size of the Input')
plt.ylabel('Time (microseconds)')
plt.title('Comparison of Recursive and Iterative Methods')
plt.ylim(0, 25)

# Save the plot to a file
plt.savefig("graph_seaborn.png")

# Show the plot
plt.show()
