class SList:
    # List() creates a new list that is empty. It needs no parameters and returns an empty list.
    def __init__(self):
        self.list = [None] * 5
        self.length = 0
        self.capacity = 4

    def get(self, idx):
        return self.list[idx]
    
    # isEmpty() tests to see whether the list is empty. It needs no parameters and returns a boolean value.
    def isEmpty(self):
        return self.length == 0

    # size() returns the number of items in the list. It needs no parameters and returns an integer.
    def size(self):
        return self.length
    
    # index(item) returns the position of item in the list. It needs the item and returns the index. Assume the item is in the list.
    def index(self, item):
        for i in range(self.length):
            if self.list[i] == item:
                return i
        return None
    
    # search(item) searches for the item in the list. It needs the item and returns a boolean value.
    def search(self, item):
        idx = self.index(item)
        return idx is not None

    # insert(pos,item) adds a new item to the list at position pos. It needs the item and returns nothing. Assume the item is not already in the list and there are enough existing items to have position pos.
    def insert(self, pos, item):
        if self.length == self.capacity:
            self.capacity *= 2
            newlist = [None] * self.capacity
            for i in range(self.length):
                newlist[i] = self.list[i]
            self.list = newlist

        if pos > self.length:
            pos = self.length
        else:
            for i in range(self.length, pos, -1):
                self.list[i] = self.list[i - 1]

        self.list[pos] = item
        self.length += 1
        #print('insert: ', self.list, ', length: ', self.length)
    
    # append(item) adds a new item to the end of the list making it the last item in the collection. It needs the item and returns nothing. Assume the item is not already in the list.
    def append(self, item):
        self.insert(self.length, item)
    
    # add(item) adds a new item to the list. It needs the item and returns nothing. Assume the item is not already in the list.
    def add(self, item):
        self.insert(0, item)
    
    # pop(pos) removes and returns the item at position pos. It needs the position and returns the item. Assume the item is in the list.
    # pop() removes and returns the last item in the list. It needs nothing and returns an item. Assume the list has at least one item.
    def pop(self, pos = None):
        if pos is None or pos >= self.length:
            pos = self.length - 1

        deleteItem = self.list[pos]
        
        for i in range(pos, self.length):
            self.list[i] = self.list[i + 1]
        self.length -= 1
        #print('delete: ', self.list, ', length: ', self.length)

        return deleteItem
    
    # remove(item) removes the item from the list. It needs the item and modifies the list. Assume the item is present in the list.
    def remove(self, item):
        return self.pop(self.index(item))


