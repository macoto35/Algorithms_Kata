package blog.ds;

import java.util.StringJoiner;

public class QueueLinkedList {
    Node head = null;

    Node tail = null;

    public String toString() {
        StringJoiner joiner = new StringJoiner(",");
        Node tmp = this.head;

        while (tmp != null) {
            joiner.add(Integer.toString(tmp.data));
            tmp = tmp.next;
        }

        return joiner.toString();
    }

    public void enqueue(int data) {
        // addLast
        Node node = new Node(data);

        if (this.tail != null)
            this.tail.next = node;

        if (this.head == null)
            this.head = node;

        this.tail = node;
    }

    public Integer dequeue() {
        // removeFirst
        if (this.empty())
            return null;

        Node delete = this.head;
        int result = delete.data;
        Node newHead = delete.next;

        this.head = newHead;

        if (newHead == null)
            this.tail = null;

        delete = null;
        return result;
    }

    public boolean empty() {
        return this.head == null;
    }
}
