package hackerRank.daysOfCode;

import java.util.*;

public class Day24 {
    public class Node {
        private int data;
        private Node next;

        public Node(int data) {
            this.data = data;
        }
    }

    public Node insert(Node head, int data) {
        Node node = new Node(data);

        if (head == null)
            return node;

        Node current = head;
        while (current.next != null)
            current = current.next;

        current.next = node;

        return head;
    }

    public void print(Node head) {
        Node current = head;

        while(current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public Node removeDuplicates(Node head) {
        Node prev = head;
        Node current = head.next;

        while (current != null) {
            while (prev.data == current.data) {
                prev.next = current.next;
                current = current.next;
            }

            prev = current;
            current = current.next;
        }

        return head;
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Node head = null;
        for (int i = 0; i < n; i++)
            head = this.insert(head, scanner.nextInt());
        this.print(head);

        head = this.removeDuplicates(head);
        this.print(head);

        scanner.close();
    }

    public static void main(String[] args) {
        Day24 day24 = new Day24();
        day24.run();
    }
}
