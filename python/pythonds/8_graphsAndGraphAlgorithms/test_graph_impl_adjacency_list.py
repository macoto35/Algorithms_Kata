import unittest
from graph_impl_adjacency_list import AdjacencyList

class TestAdjacencyList(unittest.TestCase):
    def setUp(self):
        self.list = AdjacencyList()
    
    def test_undirected_unweighted(self):
        nodes = ['A', 'B', 'C', 'D', 'E']
        for key in nodes:
            self.list.add_node(key)

        arr = [('A', 'D', 1), ('A', 'C', 1), ('B', 'C', 1), ('C', 'D', 1), ('C', 'E', 1)]
        for fromKey, toKey, weight in arr:
            self.list.add_edge(fromKey, toKey)

        self.assertFalse('F' in self.list)
        self.assertTrue('A' in self.list)
        self.assertTrue('B' in self.list)
        self.assertTrue('C' in self.list)
        self.assertTrue('D' in self.list)
        self.assertTrue('E' in self.list)


        neighbours = [('D', 1), ('C', 1)
                      , ('C', 1)
                      , ('A', 1), ('B', 1), ('D', 1), ('E', 1)
                      , ('A', 1), ('C', 1)
                      , ('C', 1)]
        i = 0
        for node in nodes:
            for item in self.list.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        i = 0
        for node in self.list.nodes():
            self.assertEqual(nodes[i], node)
            i += 1

        i = 0
        edges = [('A', 'D', 1), ('A', 'C', 1), ('B', 'C', 1), ('C', 'A', 1), ('C', 'B', 1), ('C', 'D', 1), ('C', 'E', 1), ('D', 'A', 1), ('D', 'C', 1), ('E', 'C', 1)]
        for edge in self.list.edges():
            self.assertEqual(edges[i], edge)
            i += 1

    def test_undirected_weighted(self):
        nodes = ['A', 'B', 'C', 'D', 'E']
        for key in nodes:
            self.list.add_node(key)

        arr = [('A', 'D', 5), ('A', 'C', 12), ('B', 'C', 4), ('C', 'D', 7), ('C', 'E', 3)]
        for fromKey, toKey, weight in arr:
            self.list.add_edge(fromKey, toKey, weight)

        self.assertFalse('F' in self.list)
        self.assertTrue('A' in self.list)
        self.assertTrue('B' in self.list)
        self.assertTrue('C' in self.list)
        self.assertTrue('D' in self.list)
        self.assertTrue('E' in self.list)

        neighbours = [('D', 5), ('C', 12)
                      , ('C', 4)
                      , ('A', 12), ('B', 4), ('D', 7), ('E', 3)
                      , ('A', 5), ('C', 7)
                      , ('C', 3)]
        i = 0
        for node in nodes:
            for item in self.list.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        i = 0
        for node in self.list.nodes():
            self.assertEqual(nodes[i], node)
            i += 1

        i = 0
        edges = [('A', 'D', 5), ('A', 'C', 12)
                 , ('B', 'C', 4)
                 , ('C', 'A', 12), ('C', 'B', 4), ('C', 'D', 7), ('C', 'E', 3)
                 , ('D', 'A', 5), ('D', 'C', 7)
                 , ('E', 'C', 3)]
        for edge in self.list.edges():
            self.assertEqual(edges[i], edge)
            i += 1

    def test_directed_unweighted(self):
        nodes = ['A', 'B', 'C', 'D', 'E']
        for key in nodes:
            self.list.add_node(key)

        arr = [('A', 'D', 1), ('D', 'A', 1), ('C', 'A', 1), ('C', 'B', 1), ('D', 'C', 1), ('E', 'C', 1)]
        for fromKey, toKey, weight in arr:
            self.list.add_edge(fromKey, toKey, weight, False)

        self.assertFalse('F' in self.list)
        self.assertTrue('A' in self.list)
        self.assertTrue('B' in self.list)
        self.assertTrue('C' in self.list)
        self.assertTrue('D' in self.list)
        self.assertTrue('E' in self.list)

        neighbours = [('D', 1)
                      , ('A', 1), ('B', 1)
                      , ('A', 1), ('C', 1)
                      , ('C', 1)]
        i = 0
        for node in nodes:
            for item in self.list.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        i = 0
        for node in self.list.nodes():
            self.assertEqual(nodes[i], node)
            i += 1

        i = 0
        edges = [('A', 'D', 1)
                , ('C', 'A', 1), ('C', 'B', 1)
                , ('D', 'A', 1), ('D', 'C', 1)
                , ('E', 'C', 1)]
        for edge in self.list.edges():
            self.assertEqual(edges[i], edge)
            i += 1

    def test_directed_weighted(self):
        nodes = ['A', 'B', 'C', 'D', 'E']
        for key in nodes:
            self.list.add_node(key)

        arr = [('A', 'D', 2), ('D', 'A', 10), ('C', 'A', 12), ('C', 'B', 4), ('D', 'C', 7), ('E', 'C', 3)]
        for fromKey, toKey, weight in arr:
            self.list.add_edge(fromKey, toKey, weight, False)

        self.assertFalse('F' in self.list)
        self.assertTrue('A' in self.list)
        self.assertTrue('B' in self.list)
        self.assertTrue('C' in self.list)
        self.assertTrue('D' in self.list)
        self.assertTrue('E' in self.list)

        neighbours = [('D', 2)
                      , ('A', 12), ('B', 4)
                      , ('A', 10), ('C', 7)
                      , ('C', 3)]
        i = 0
        for node in nodes:
            for item in self.list.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        i = 0
        for node in self.list.nodes():
            self.assertEqual(nodes[i], node)
            i += 1

        i = 0
        edges = [('A', 'D', 2)
                , ('C', 'A', 12), ('C', 'B', 4)
                , ('D', 'A', 10), ('D', 'C', 7)
                , ('E', 'C', 3)]
        for edge in self.list.edges():
            self.assertEqual(edges[i], edge)
            i += 1

if __name__ == '__main__':
    unittest.main()
