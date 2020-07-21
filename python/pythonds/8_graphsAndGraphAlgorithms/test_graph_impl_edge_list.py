import unittest
from graph_impl_edge_list import EdgeListGraph 

class TestGraphImplEdgeList(unittest.TestCase):
    def setUp(self):
        self.g = EdgeListGraph()

    def test_undirected_unweighted(self):
        arr = [('A', 'D', 1), ('A', 'C', 1), ('B', 'C', 1), ('C', 'D', 1), ('C', 'E', 1)]
        for fromKey, toKey, weight in arr:
            self.g.add_edge(fromKey, toKey)

        self.assertFalse('F' in self.g)
        self.assertTrue('A' in self.g)
        self.assertTrue('B' in self.g)
        self.assertTrue('C' in self.g)
        self.assertTrue('D' in self.g)
        self.assertTrue('E' in self.g)

        nodes = ['A', 'B', 'C', 'D', 'E']
        neighbours = [('D', 1), ('C', 1), ('C', 1), ('A', 1), ('B', 1), ('D', 1), ('E', 1), ('A', 1), ('C', 1), ('C', 1)]
        i = 0
        for node in nodes:
            for item in self.g.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        tmpNodes = ['A', 'D', 'C', 'B', 'E']
        i = 0
        for node in self.g.nodes():
            self.assertEqual(tmpNodes[i], node)
            i += 1

        i = 0
        for edge in self.g.edges():
            self.assertEqual(arr[i], edge)
            i += 1

    def test_undirected_weighted(self):
        arr = [('A', 'D', 5), ('A', 'C', 12), ('B', 'C', 4), ('C', 'D', 7), ('C', 'E', 3)]
        for fromKey, toKey, weight in arr:
            self.g.add_edge(fromKey, toKey, weight)

        self.assertFalse('F' in self.g)
        self.assertTrue('A' in self.g)
        self.assertTrue('B' in self.g)
        self.assertTrue('C' in self.g)
        self.assertTrue('D' in self.g)
        self.assertTrue('E' in self.g)

        nodes = ['A', 'B', 'C', 'D', 'E']
        neighbours = [('D', 5), ('C', 12), ('C', 4), ('A', 12), ('B', 4), ('D', 7), ('E', 3), ('A', 5), ('C', 7), ('C', 3)]
        i = 0
        for node in nodes:
            for item in self.g.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        tmpNodes = ['A', 'D', 'C', 'B', 'E']
        i = 0
        for node in self.g.nodes():
            self.assertEqual(tmpNodes[i], node)
            i += 1

        i = 0
        for edge in self.g.edges():
            self.assertEqual(arr[i], edge)
            i += 1

    def test_directed_unweighted(self):
        arr = [('A', 'D', 1), ('D', 'A', 1), ('C', 'A', 1), ('C', 'B', 1), ('D', 'C', 1), ('E', 'C', 1)]
        for fromKey, toKey, weight in arr:
            self.g.add_edge(fromKey, toKey)

        self.assertFalse('F' in self.g)
        self.assertTrue('A' in self.g)
        self.assertTrue('B' in self.g)
        self.assertTrue('C' in self.g)
        self.assertTrue('D' in self.g)
        self.assertTrue('E' in self.g)

        nodes = ['A', 'B', 'C', 'D', 'E']
        neighbours = [('D', 1), ('D', 1), ('C', 1), ('C', 1), ('A', 1), ('B', 1), ('D', 1), ('E', 1), ('A', 1), ('A', 1), ('C', 1), ('C', 1)]
        i = 0
        for node in nodes:
            for item in self.g.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        tmpNodes = ['A', 'D', 'C', 'B', 'E']
        i = 0
        for node in self.g.nodes():
            self.assertEqual(tmpNodes[i], node)
            i += 1

        i = 0
        for edge in self.g.edges():
            self.assertEqual(arr[i], edge)
            i += 1

    def test_directed_weighted(self):
        arr = [('A', 'D', 2), ('D', 'A', 10), ('C', 'A', 12), ('C', 'B', 4), ('D', 'C', 7), ('E', 'C', 3)]
        for fromKey, toKey, weight in arr:
            self.g.add_edge(fromKey, toKey, weight)

        self.assertFalse('F' in self.g)
        self.assertTrue('A' in self.g)
        self.assertTrue('B' in self.g)
        self.assertTrue('C' in self.g)
        self.assertTrue('D' in self.g)
        self.assertTrue('E' in self.g)

        nodes = ['A', 'B', 'C', 'D', 'E']
        neighbours = [('D', 2), ('D', 10), ('C', 12), ('C', 4), ('A', 12), ('B', 4), ('D', 7), ('E', 3), ('A', 2), ('A', 10), ('C', 7), ('C', 3)]
        i = 0
        for node in nodes:
            for item in self.g.neighbours(node):
                self.assertEqual(neighbours[i], item)
                i += 1

        tmpNodes = ['A', 'D', 'C', 'B', 'E']
        i = 0
        for node in self.g.nodes():
            self.assertEqual(tmpNodes[i], node)
            i += 1

        i = 0
        for edge in self.g.edges():
            self.assertEqual(arr[i], edge)
            i += 1

if __name__ == '__main__':
    unittest.main()
