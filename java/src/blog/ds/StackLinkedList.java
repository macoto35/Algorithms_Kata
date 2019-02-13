package blog.ds;

import java.util.StringJoiner;

public class StackLinkedList {
    Node head = null;

    public String toString() {
        StringJoiner joiner = new StringJoiner(",");
        Node tmp = this.head;

        while(tmp != null) {
            joiner.add(Integer.toString(tmp.data));
            tmp = tmp.next;
        }

        return joiner.toString();
    }

    // addFirst
    public void push(int data) {
        Node node = new Node(data);

        node.next = this.head;
        this.head = node;
    }

    // removeFirst
    public Integer pop() {
        if (this.empty()) {
            return null;
        } else {
            Node delete = this.head;
            int result = delete.data;
            Node newHead = delete.next;

            this.head = newHead;

            delete = null;
            return result;
        }
    }

    public boolean empty() {
        return this.head == null;
    }

    public Integer peek() {
        if (this.empty())
            return null;
        return this.head.data;
    }

    public int search(int data) {
        Node tmp = this.head;
        int idx = 0;

        while(tmp != null) {
            if (data == tmp.data)
                return idx;
            idx++;
            tmp = tmp.next;
        }
        return -1;
    }
}
