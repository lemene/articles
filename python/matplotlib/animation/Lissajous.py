# http://www.jb51.net/article/66441.htm

# -*- coding: utf-8 -*- 
import numpy as np 
import matplotlib.pyplot as plt 
import matplotlib.animation as animation 

(m, n) = (13, 18)

#第一个参数必须为framenum 
# x = sin(m · t), y = sin(n · t)
def update_line(t, data, line):  
    print(t)
    line.set_data(np.hstack((line.get_data(), np.array([[np.sin(m*t/100)],[np.sin(n*t/100)]])))) 
    return line, 

fig1 = plt.figure() 
data = np.random.rand(2, 15) 
l, = plt.plot([], [], 'r-') 

plt.xlim(-1, 1) 
plt.ylim(-1, 1) 
plt.xlabel('x') 
plt.title('test') 

#framenum从1增加大25后,返回再次从1增加到25,再返回... 
line_ani = animation.FuncAnimation(fig1, update_line, 1000, fargs=(data, l), interval=200, blit=True) 

plt.show() 
