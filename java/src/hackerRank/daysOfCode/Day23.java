package hackerRank.daysOfCode;

import java.util.*;

/*
- Tree Traversal:
  * InOrder
  * PostOrder
  * PreOrder (Depth-first-search, DFS)
  * Level-Order (Breadth-first-search, BFS)
*/
public class Day23 {
    public class Node<T> {
        public T data;
        public Node left;
        public Node right;

        public Node (T data) {
            this.data = data;
        }
    }

    public Node<Integer> insert(Node<Integer> root, int data) {
        if (root == null)
            return new Node<Integer>(data);

        if (data <= root.data)
            root.left = this.insert(root.left, data);
        else
            root.right = this.insert(root.right, data);

        return root;
    }

    public void levelOrder(Node<Integer> root) {
        Queue<Node<Integer>> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node node = queue.remove();
            System.out.print(node.data + " ");

            if (node.left != null)
                queue.add(node.left);

            if (node.right != null)
                queue.add(node.right);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        Node root = null;
        Day23 day23 = new Day23();
        for (int i = 0; i < t; i++)
            root = day23.insert(root, scanner.nextInt());

        day23.levelOrder(root);
        scanner.close();
    }

}
