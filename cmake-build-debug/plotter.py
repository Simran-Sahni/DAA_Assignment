import numpy as np
import matplotlib.pyplot as plt


for idx in range(1,16):
    file_name = "input-plot" + str(idx) + ".txt"
    print(file_name)
    x = np.loadtxt(file_name)
    fig = plt.figure(figsize=(12, 12))
    for i in x:
        if (i[4] == 0):
            plt.plot([i[0], i[2]], [i[1], i[3]], color='red')
        else:
            plt.plot([i[0], i[2]], [i[1], i[3]], color='green')
    plt.suptitle('Input Test Case ' + str(idx), fontsize=25)
    plt.savefig("Input" + str(idx) + ".pdf")

for idx in range(1,16):
    file_name = "output-plot" + str(idx) + ".txt"
    f = open(file_name,"r")
    lines = f.readlines();
    measure = lines[0]
    perimeter = lines[1]

    print(file_name)
    x = np.loadtxt(file_name,skiprows = 2)
    fig = plt.figure(figsize=(12, 12))
    for i in x:
        if (i[4] == 0):
            plt.plot([i[0], i[2]], [i[1], i[3]], color='red')
        else:
            plt.plot([i[0], i[2]], [i[1], i[3]], color='green')
    plt.title('Output Test Case ' + str(idx),fontsize=22)
    text = measure + '\n' + perimeter
    plt.suptitle(text, fontsize=18)
    plt.savefig("Output" + str(idx) + ".pdf")