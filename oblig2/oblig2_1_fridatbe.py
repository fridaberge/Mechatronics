from matplotlib import pyplot as plt
import numpy as np

V = np.arange(1, 10, 0.1)
plt.xticks(np.arange(min(V), max(V)+1, 1))
I = V/100 #100 er resistatnsen
plt.title("Strømmen ved 100 Ohm resistans")
plt.xlabel("Spenning(V)")
plt.ylabel("Strøm (A)")
plt.plot(V,I, label='I (strøm)')
plt.legend()
plt.grid()
# plt.show(), brukte savefig i stedet for show
plt.savefig("opg1.png");