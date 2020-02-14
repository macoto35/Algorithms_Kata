class HashTable:
    def __init__(self):
        self.size = 11
        self.length = 0
        self.slots = [None] * self.size
        self.data = [None] * self.size

    def put(self, key, data):
        hashval = self._gethash(key)
        
        if self.slots[hashval] is None:
            self.slots[hashval] = key
            self.length += 1
        self.data[hashval] = data

    def get(self, key):
        hashval = self._gethash(key)
        return self.data[hashval]
    
    def _hashfunction(self, key):
        return key % self.size

    def _rehash(self, oldhash):
        return (oldhash + 1) % self.size

    def _gethash(self, key):
        hashval = self._hashfunction(key)
        originalHashVal = hashval
        stop = False

        while self.slots[hashval] is not None and self.slots[hashval] != key and not stop:
            hashval = self._rehash(hashval)
            if originalHashVal == hashval:
                stop = True

        return hashval

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, data):
        self.put(key, data)

    def __delitem__(self, key):
        hashval = self._gethash(key)
        self.length -= 1
        self.slots[hashval] = self.data[hashval] = None
    
    def __len__(self):
        return self.length
    
    def __contains__(self, key):
        return self.get(key) is not None
