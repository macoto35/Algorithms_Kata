'''
* Graph Component
- Vertex: Node. key = name, payload = other data
- Edge: Arc. Connects two vertices. one way = directed graph or digraph, two way = indirected graph
- weight: Edges may be weighted to show that there is a cost to go from one vertex to antoher. e.g. distance between the two cities
- path: A sequence of vertices that are connected by edges. unweighted path length = the number of edges in the path. weighted path length = the sum of the weights of all the edges in the path.
- cycle: In a directed graph is a path that starts and ends at the same vertex. graph with no cycle = acyclic graph. directed graph with no cycle = directed acyclic graph (DAG)

* Graph G, set of vertices V, set of edges E
G = (V, E)
Each edge is tuple (i, j, w) when i, j = vertices, w = weight
V = {V0, V1, v2, V3, V4, V5}
E = {(v0, v1, 5), (v1, v2, 5), (v2, v3, 9), (v3, v4, 7), (v4, v0, 1), (v0, v5, 2), (v5, v4, 8), (v5, v2, 1), (v3, v5, 3)}

* well-known implementation
- edge list
- adjacency matrix
- adjacency list
- nested hash table

'''
class Graph:
    # Graph(): creates a new, empty graph
    def __init__(self):
        pass

    # adds an instance of vertex to the graph
    def addVertex(self, vert):
        pass

    # adds a new, directed edge to the graph that connects two vertices
    def addEdge(self, fromVert, toVert):
        pass

    # addes a new, weighted, directed edge to the graph that connects two vertices
    def addEdge(self, fromVert, toVert, weight):
        pass

    # finds a vertex in the graph named key
    def getVertex(self, key):
        pass

    # returns the list of all vertices in the graph
    def getVertices(self):
        pass

    # in: returns True for a statement of the form vertex in graph, if the given vertex is not in the graph, False otherwise
    def __contains__(self, vert):
        pass
