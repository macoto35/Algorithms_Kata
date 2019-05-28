package hackerRank.daysOfCode;

import java.util.*;

public class Day15 {

    public class Node {
        private int data;

        private Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    public void display(Node head) {
        Node current = head;
        while(current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
    }

    public Node insert(Node head, int data) {
        Node node = new Node(data);

        if (head == null) {
            return node;
        } else {
            Node current = head;
            while (current.next != null)
                current = current.next;
            current.next = node;

            return head;
        }
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Node head = null;
        for (int i = 0; i < n; i++)
            head = this.insert(head, scanner.nextInt());

        this.display(head);
    }

    public static void main(String[] args) {
        Day15 day15 = new Day15();
        day15.run();
    }
}
