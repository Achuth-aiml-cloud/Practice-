import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = {'InputSize': [], 'RecFib': [], 'IterFib': [], 'RecCubes': [], 'IterCubes': []}


with open('results.txt', 'r') as file:
    for line in file:
        inputs, fibrecValue, fibiterValue, sumrecValue, sumiterValue = map(float, line.strip().split(','))
        data['InputSize'].append(inputs)
        data['RecFib'].append(fibrecValue)
        data['IterFib'].append(fibiterValue)
        data['RecCubes'].append(sumrecValue)
        data['IterCubes'].append(sumiterValue)


df = pd.DataFrame(data)


df_melted = df.melt(id_vars=['InputSize'], var_name='Method', value_name='Time')


sns.set_theme(style="whitegrid")
plt.figure(figsize=(10, 6))
sns.lineplot(data=df_melted, x='InputSize', y='Time', hue='Method', style='Method', markers=True, dashes=False)


plt.xlabel('Input')
plt.ylabel('Time in us(microseconds)')
plt.title('Input VS Time in Micro Seconds ')
plt.ylim(0, 25)


plt.savefig("graph_seaborn.png")


plt.show()
