import math
from matplotlib import pyplot as plt
import numpy as np


V = np.arange(0, 1.4, 0.01)
I_0 = 1*10**(-12)
K = 1.38064853*10**(-23)
q = abs(1.6020*10**(-19))
T = 300
n = 1.6 
I = I_0* (math.e**(q*V/(n*K*T)) -1)
plt.ylim(0,2)
plt.title("Strømmen ved n = 1.6")
plt.xlabel("Spenning(V)")
plt.ylabel("Strøm (A)")
plt.plot(V,I, label='I (strøm)')
plt.legend()
plt.grid()
# plt.show(), brukte savefig i stedet for show
plt.savefig("opg1.png");
V = 1.14
I_2 = I_0* (math.e**(q*V/(n*K*T)) -1)
n = 1.3
I_3 = I_0* (math.e**(q*V/(n*K*T)) -1)
print(I_2) #->  0.9293037177410425
print(I_3) #-> 537.0815268226955