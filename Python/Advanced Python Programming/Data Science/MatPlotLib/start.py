from matplotlib import pyplot as plt
import math

_range = 50
step = 0.0001

x = [(n)/step for n in range(1, _range)]
_O1 = [(1)/step for n in range(1, _range)]
_Ologn = [(math.log(n))/step for n in range(1, _range)]
_On = [(n)/step for n in range(1, _range)]
_On2 = [(n**2)/step for n in range(1, _range)]
_Onlogn = [(n*math.log(n))/step for n in range(1, _range)]
_O2n = [(2**n)/step for n in range(1, _range)]
_Ofn = [(math.factorial(n))/step for n in range(1, _range)]
plt.plot(x, _O1)
plt.plot(x, _Ologn)
plt.plot(x, _On)
plt.plot(x, _On2)
plt.plot(x, _Onlogn)
# plt.plot(x, _O2n)
# plt.plot(x, _Ofn)
plt.title("Time Complexity")
plt.show()

