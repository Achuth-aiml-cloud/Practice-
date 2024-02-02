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


df_rec = df_melted[df_melted['Method'].str.contains('Rec')]
df_iter = df_melted[df_melted['Method'].str.contains('Iter')]

sns.set_theme(style="whitegrid")


fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(16, 6))


sns.lineplot(data=df_rec, x='InputSize', y='Time', hue='Method', style='Method', markers=True, dashes=False, ax=axes[0])
axes[0].set_xlabel('Input')
axes[0].set_ylabel('Time in us (microseconds)')
axes[0].set_title('Recursive Methods')
axes[0].set_ylim(0, 25)


sns.lineplot(data=df_iter, x='InputSize', y='Time', hue='Method', style='Method', markers=True, dashes=False, ax=axes[1])
axes[1].set_xlabel('Input')
axes[1].set_ylabel('Time in us (microseconds)')
axes[1].set_title('Iterative Methods')
axes[1].set_ylim(0, 25)

plt.savefig("graph_seaborn.png")
plt.show()
