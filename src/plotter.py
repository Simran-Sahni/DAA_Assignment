import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt("output_edges.txt")

for i in x:
	if(i[4] == 0):
		plt.plot([i[0],i[2]],[i[1],i[3]], color='red')
	else:
		plt.plot([i[0],i[2]],[i[1],i[3]], color='green')

plt.savefig("output.png")
plt.show()
		
			
