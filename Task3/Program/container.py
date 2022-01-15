import rectangle
import triangle

#----------------------------------------------
class Container:
    def __init__(self):
        self.store = []

    def Write(self, ostream):
        ostream.write("Container contains {} elements.\n".format(len(self.store)))
        for shape in self.store:
            shape.Write(ostream)
            ostream.write("\n")
        ostream.write("\n")
        pass



    def Swap(self, i, j):
        temp = self.store[i]
        self.store[i] = self.store[j]
        self.store[j] = temp

    def BinarySearch(self, searched, left, right):
        mid = (left + right) // 2;
        if mid == left:
            if searched.Perimetr() < self.store[left].Perimetr():
                return left
            else:
                return left + 1
        if searched.Perimetr() < self.store[mid].Perimetr():
            return self.BinarySearch(searched, left, mid)
        if searched.Perimetr() == self.store[mid].Perimetr():
            return mid + 1
        else:
            return self.BinarySearch(searched, mid, right)

    def BinarySort(self, length):
        if length <= 1 or length > 10000:
            return
        for i in range(1, length):
            ind = self.BinarySearch(self.store[i], 0, i)
            for j in range(i, ind, -1):
                self.Swap(j, j-1);
