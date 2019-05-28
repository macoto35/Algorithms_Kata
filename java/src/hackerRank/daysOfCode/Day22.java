package hackerRank.daysOfCode;

import java.util.*;

/*
- Binary Tree: Composed of nodes connected by edges. Has maximum 2 children(left and right).
  * Root: top node
  * Children / Parent: A node's left and right subtrees are children. That node can be referred to as the parent.
  * Leaf: non-root node with no children
  * Ancestor: a is ancestor or b === if b is located in a left or right subtree whose root node is a
  * Depth(Level): distance from the root node
  * Height: # of edges between the root and the node.

- Binary Search Tree(BST): binary tree that is satisfies the following three conditions,
  1. each elements in the left subtree is less than or equal to the root element
  2. each elements in the right subtree is greater than the root element
  3. both left and right tree are BST
  -> leftChild <= root < rightChild
*/
public class Day22 {
    public class Node {
        private int data;

        private Node left;

        private Node right;

        public Node(int data) {
            this.data = data;
        }
    }

    public Node insert(Node root, int data) {
        if (root == null)
            return new Node(data);

        if (data <= root.data)
            root.left = this.insert(root.left, data);
        else
            root.right = this.insert(root.right, data);

        return root;
    }

    public void printTree(Node root) {
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);

        while(!queue.isEmpty()) {
            Node current = queue.remove();
            System.out.println("data: " + current.data);

            if (current.left != null)
                queue.add(current.left);

            if (current.right != null)
                queue.add(current.right);
        }
    }

    public int getHeight(Node root) {
        if (root == null)
            return -1;
        return 1 + Math.max(this.getHeight(root.left), this.getHeight(root.right));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Day22 day22 = new Day22();
        Node root = null;

        for (int i = 0; i < n; i++)
            root = day22.insert(root, scanner.nextInt());
        // day22.printTree(root);

        System.out.println(day22.getHeight(root));
    }
}
