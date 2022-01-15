from colour import *
import math

#----------------------------------------------
class Circle:
    def __init__(self, n):
        self.colour = ""
        self.ox = 0
        self.oy = 0
        self.r = 0

        self.n = n

    def ReadStrArray(self, strArray, i):
        # должно быть как минимум 4 непрочитанных значения в массиве
        if i >= len(strArray) - 3:
            return 0
        self.ox = int(strArray[i])
        self.oy = int(strArray[i+1])
        self.r = int(strArray[i+2])
        self.colour = getColour(int(strArray[i+3]))
        i += 4
        return i

    def Write(self, ostream):
        ostream.write("Circle: center({}, {}) | radius = {} | {} | perimetr = {}".format(
            self.ox, self.oy, self.r, self.colour, self.Perimetr()))
        pass

    def Perimetr(self):
        return 2 * math.pi * self.r
        pass
