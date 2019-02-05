package blog.ds;

import java.util.StringJoiner;

public class LinkedList {
    Node head = null;

    Node tail = null;

    int length = 0;

    public String toString() {
        StringJoiner sj = new StringJoiner(",");

        Node tmp = this.head;
        while (tmp != null){
            sj.add(Integer.toString(tmp.data));
            tmp = tmp.next;
        }

        return sj.toString();
    }

    public void addFirst(int input) {
        Node node = new Node(input, null);

        if (this.head != null)
            node.next = this.head;

        if (this.tail == null)
            this.tail = node;

        this.head = node;
        this.length++;
    }

    public void addLast(int input) {
        Node node = new Node(input, null);

        if (this.tail != null)
            this.tail.next = node;

        if (this.head == null)
            this.head = node;

        this.tail = node;
        this.length++;
    }

    private Node getNode(int idx) {
        Node tmp = this.head;
        for (int i = 0; i < idx; i++) {
            if (tmp.next != null)
                tmp = tmp.next;
        }

        return tmp;
    }

    public void addFront(int input, int idx) {
        if (idx == 0) {
            this.addFirst(input);
        } else if (idx >= this.length) {
            this.addLast(input);
        } else {
            Node prev = this.getNode(idx - 1);

            Node node = new Node(input, null);
            node.next = prev.next;
            prev.next = node;
            this.length++;
        }
    }

    public void addBack(int input, int idx) {
        if (idx >= this.length) {
            this.addLast(input);
        } else {
            Node current = this.getNode(idx);

            Node node = new Node(input, null);
            node.next = current.next;
            current.next = node;

            if (node.next == null)
                this.tail = node;

            this.length++;
        }
    }

    public Integer removeFirst() {
        if (this.empty())
            return null;

        Node delete = this.head;
        Integer result = delete.data;
        this.head = delete.next;

        if (delete.next == null)
            this.tail = null;

        delete = null;
        this.length--;

        return result;
    }

    public Integer remove(int idx) {
        if (idx == 0) {
            return this.removeFirst();
        } else if (idx >= this.length) {
            return null;
        } else {
            Node prev = this.getNode(idx - 1);
            Node delete = prev.next;
            Integer result = delete.data;

            prev.next = delete.next;
            if (prev.next == null)
                this.tail = prev;

            delete = null;
            this.length--;

            return result;
        }
    }

    public Integer removeLast() {
        if (empty())
            return null;
        return this.remove(this.length - 1);
    }

    public boolean empty() {
        return this.head == null;
    }

    public int size() {
        return this.length;
    }

    public Integer get(int idx) {
        if (idx < 0 || idx >= this.length)
            return null;

        return this.getNode(idx).data;
    }

    public int indexOf(int data) {
        Node tmp = this.head;
        for (int i = 0; i < this.length; i++) {
            if (tmp.data == data)
                return i;
            tmp = tmp.next;
        }

        return -1;
    }
}
