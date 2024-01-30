import matplotlib.pyplot as plt 
inputSize = []

recFab = []
iteFab = []

recCube = []
iteCube = []

with open('data.txt','r') as f:
    for i in f:
        timeData = i.strip().split(',')

        if len(timeData) != 5:
            continue

        inputs , fibrecValue , fibiterValue , sumrecValue , sumiterValue = map(float , timeData)

        inputSize.append(inputs)
        recFab.append(fibrecValue )
        iteFab.append(fibiterValue)
        recCube.append(sumrecValue)
        iteCube.append(fibrecValue)

plt.plot(inputSize,recFab, label = 'Fibonacci Recursive'  , linestyle='--')
plt.plot(inputSize,iteFab, label = 'Fibonacci Iterative' ,  linestyle=':')
plt.plot(inputSize,recCube, label = 'Sum of Cubes Recursive' , linestyle='--')
plt.plot(inputSize,iteCube, label = 'Sum of Cubes Iterative'  , linestyle=':')
        
plt.xlabel('Size of the Input  --->')
plt.ylabel('Time --->')
plt.ylim(0,0.01)
plt.title('Graph')
plt.legend()
plt.savefig("graph.png")