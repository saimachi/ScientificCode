import matplotlib.pyplot as mpl
import math

x_position = []
y_position = [] 

for time in range(0, 37, 6): #6 intervals
    time_local = time/10
    x_position.append(30*time_local*math.cos(math.radians(35)))
    y_position.append(30*time_local*math.sin(math.radians(35)) - (9.81 * (time_local)**2)/2)

mpl.plot(x_position, y_position)
mpl.xlabel("x-position")
mpl.ylabel("y-position")
mpl.title("x-position vs. y-position of a projectile")
mpl.show()
    
