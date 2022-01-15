from colour import *
import math

#----------------------------------------------
class Rectangle:
    def __init__(self, n):
        self.colour = ""
        self.ax = 0
        self.ay = 0
        self.bx = 0
        self.by = 0

        self.n = n

    def ReadStrArray(self, strArray, i):
        # должно быть как минимум 5 непрочитанных значения в массиве
        if i >= len(strArray) - 4:
            return 0
        self.ax = int(strArray[i])
        self.ay = int(strArray[i+1])
        self.bx = int(strArray[i+2])
        self.by = int(strArray[i+3])
        self.colour = getColour(int(strArray[i+4]))
        i += 5
        return i

    def Write(self, ostream):
        ostream.write("Rectangle: leftUpper({}, {}) | rightDown({}, {}) | {} | perimetr = {}".format(
            self.ax, self.ay, self.bx, self.by, self.colour, self.Perimetr()))
        pass

    def Perimetr(self):
        return 2 * (self.bx - self.ax) + 2 * (self.ay - self.by)
        pass
