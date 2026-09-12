from matplotlib import pyplot as plt
import numpy as np

R = np.arange(1, 1000, 0.1)
V = 10*(R/(R+150))

plt.title("Spenningen over R1")
plt.xlabel("Resistans (Ohm)")
plt.ylabel("Spenning (Volt)")
plt.plot(R, V, label='V (spenning)')
plt.legend()
plt.grid()
# plt.show(), brukte savefig i stedet for show
plt.savefig("opg2.png");