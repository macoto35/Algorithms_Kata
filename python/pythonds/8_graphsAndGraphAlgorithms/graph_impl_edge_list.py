'''
total memory requirements = number of edges in the graph

Pros:
- sparse(graphs where each node has relatively few neighbours) graph will be small

Cons:
- cannot represent solitary nodes
- dense(graphs where each node has many neighbours) graph will be large, worst case: fully connected graph (# of edges is O(N**2) where N is # of nodes)
'''
class EdgeListGraph:
    def __init__(self):
        self.list = []
    
    # unable
    def add_node(self, key):
        pass
    
    # O(1)
    def add_edge(self, fromKey, toKey, weight = 1):
        self.list.append((fromKey, toKey, weight))

    # O(E)
    def neighbours(self, key):
        for fromKey, toKey, weight in self.list:
            if fromKey == key:
                yield (toKey, weight)
            elif toKey == key:
                yield (fromKey, weight)

    # O(E)
    def __contains__(self, key):
        for fromKey, toKey, weight in self.list:
            if fromKey == key or toKey == key:
                return True
        return False
    
    # O(E)
    def nodes(self):
        allNode = {}
        for fromKey, toKey, weight in self.list:
            if fromKey not in allNode:
                allNode[fromKey] = 1
                yield fromKey

            if toKey not in allNode:
                allNode[toKey] = 1
                yield toKey

    # O(E)
    def edges(self):
        for item in self.list:
            yield item

