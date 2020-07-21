'''
Implementation: 1. Array - Array or 2. Array - Hashmap
PRO: efficient memory 
CON: checking for the existence of all edges between two nodes takes O(N) - slower than the adjacency matrix O(1), one of the weaknesses of the adjacency list
'''
class AdjacencyList:
    def __init__(self):
        self.list = []
        self.allNodeDict = {}

    # O(1)
    def add_node(self, key):
        self.list.append([key, {}])
        self.allNodeDict[key] = len(self.list) - 1

    # O(1)
    def add_edge(self, fromKey, toKey, weight = 1, unDirected = True):
        fromIdx = self.allNodeDict[fromKey]
        toIdx = self.allNodeDict[toKey]
        self.list[fromIdx][1][toKey] = weight

        if unDirected:
            self.list[toIdx][1][fromKey] = weight

    # O(N)
    def neighbours(self, key):
        idx = self.allNodeDict[key]
        for key, weight in self.list[idx][1].items():
            yield (key, weight)

    # O(1)
    def __contains__(self, key):
        return key in self.allNodeDict

    # O(N)
    def nodes(self):
        for item in self.list:
            yield item[0]

    # O(N+E)
    def edges(self):
        for node in self.list:
            for key, weight in node[1].items():
                yield node[0], key, weight

