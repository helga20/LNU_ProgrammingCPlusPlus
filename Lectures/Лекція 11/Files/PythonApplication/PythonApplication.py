import struct
import matplotlib.pyplot as plt

file = open(r'..\Files\table.dat', 'rb')
xList = [] # список значень аргумента (абсциси)
yList = [] # список значень функції   (ординати)
while True:
    data = file.read(16)
    if data == b'': break # досягли кінця файла
    # двійкові дані треба перетворити на дійсні числа
    x, y = struct.unpack('2d', data)
    xList.append(x)
    yList.append(y)
# графічне відображення прочитаних чисел
plt.plot(xList, yList)
plt.title('Plot of y=sin(x) for x=0(0.2)6.2')
plt.show()

'''file.seek(0)
data = file.read()
file.close()
data = struct.unpack('d'*(len(data)//8),data)
xList = data[0::2]
yList = data[1::2]'''
