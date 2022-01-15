from colour import *
import math

#----------------------------------------------
class Triangle:
    def __init__(self, n):
        self.colour = ""
        self.ax = 0
        self.ay = 0
        self.bx = 0
        self.by = 0
        self.cx = 0
        self.cy = 0

        self.n = n

    def ReadStrArray(self, strArray, i):
        # должно быть как минимум 7 непрочитанных значения в массиве
        if i >= len(strArray) - 6:
            return 0
        self.ax = int(strArray[i])
        self.ay = int(strArray[i+1])
        self.bx = int(strArray[i+2])
        self.by = int(strArray[i+3])
        self.cx = int(strArray[i+4])
        self.cy = int(strArray[i+5])
        self.colour = getColour(int(strArray[i+6]))
        i += 7
        return i

    def Write(self, ostream):
        ostream.write("Triangle: first({}, {}) | second({}, {}) | third({}, {}) | {} | perimetr = {}".format(
            self.ax, self.ay, self.bx, self.by, self.cx, self.cy, self.colour, self.Perimetr()
        ))
        pass

    def Perimetr(self):
        first = math.sqrt((self.bx-self.ax)*(self.bx-self.ax) + (self.by-self.ay)*(self.by-self.ay))
        second = math.sqrt((self.bx-self.cx)*(self.bx-self.cx) + (self.by-self.cy)*(self.by-self.cy))
        third = math.sqrt((self.cx - self.ax) * (self.cx - self.ax) + (self.cy - self.ay) * (self.cy - self.ay))
        return first + second + third
        pass

