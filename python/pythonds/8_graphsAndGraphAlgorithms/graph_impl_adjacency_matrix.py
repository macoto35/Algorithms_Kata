'''
pros:
- checking existence of an edge between any two nodes is O(1)
- get neighbours is O(N)
- if you know the size of graph before and it is dense graph (especially, full connected graph)
- if you frequently checking for the existence of all edges between two nodes

cons:
- waste of memory if graph is sparse graph

'''
class AdjacencyMatrix:
    def __init__(self, n):
        self.matrix = [[-1 for i in range(n)] for j in range(n)]
        self.allNodesDict = {}
        self.allNodesArr = []
        self.idx = 0

    # O(N**2), O(1) if we know the size of nodes before and pre allowcate the memory
    def add_node(self, key):
        size = len(self.matrix)
        tmpMatrix = [[-1 for i in range(size + 1)] for j in range(size + 1)]

        for i in range(size):
            for j in range(size):
                tmpMatrix[i][j] = self.matrix[i][j]
        self.matrix = tmpMatrix

        self.allNodesDict[key] = self.idx
        self.allNodesArr.append(key)
        self.idx += 1

    # O(1)
    def add_edge(self, fromKey, toKey, weight = 1, unDirected = True):
        fromIdx = self.allNodesDict[fromKey]
        toIdx = self.allNodesDict[toKey]

        self.matrix[fromIdx][toIdx] = weight
        if unDirected:
            self.matrix[toIdx][fromIdx] = weight

    # O(N)
    def neighbours(self, key):
        idx = self.allNodesDict[key]

        for i in range(len(self.matrix)):
            if self.matrix[idx][i] != -1:
                yield (self.allNodesArr[i], self.matrix[idx][i])

    # O(1)
    def __contains__(self, key):
        return key in self.allNodesDict

    # O(N)
    def nodes(self):
        for key in self.allNodesArr:
            yield key

    # O(N**2)
    def edges(self):
        size = len(self.matrix)

        for i in range(size):
            for j in range(size):
                if self.matrix[i][j] != -1:
                    yield (self.allNodesArr[i], self.allNodesArr[j], self.matrix[i][j])



