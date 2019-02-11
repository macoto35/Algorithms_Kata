package blog.ds;

import java.util.StringJoiner;

public class DoublyLinkedList {
    private Node head = null;

    private Node tail = null;

    private int length = 0;


    public String toString() {
        StringJoiner joiner = new StringJoiner(",");

        Node tmp = this.head;
        while (tmp != null) {
            joiner.add(Integer.toString(tmp.data));
            tmp = tmp.next;
        }

        return joiner.toString();
    }

    public void addFirst(int input) {
        Node node = new Node(input);

        if (this.head != null) {
            node.next = this.head;
            this.head.prev = node;
        }

        if (this.tail == null)
            this.tail = node;

        this.head = node;
        this.length++;
    }

    public void addLast(int input) {
        Node node = new Node(input);

        if (this.tail != null) {
            this.tail.next = node;
            node.prev = this.tail;
        }

        if (this.head == null)
            this.head = node;

        this.tail = node;
        this.length++;
    }

    private Node getNode(int idx) {
        if (idx < this.length / 2) {
            Node tmp = this.head;

            for (int i = 0; i < idx; i++) {
                if (tmp != null)
                    tmp = tmp.next;
            }

            return tmp;
        } else {
            Node tmp = this.tail;

            for (int i = this.length - 1; i > idx; i--) {
                if (tmp != null)
                    tmp = tmp.prev;
            }

            return tmp;
        }
    }

    public void addFront(int input, int idx) {
        if (idx == 0) {
            this.addFirst(input);
        } else if (idx >= this.length) {
            this.addLast(input);
        } else {
            Node newNode = new Node(input);
            Node nextNode = this.getNode(idx);
            Node prevNode = nextNode.prev;

            prevNode.next = newNode;
            newNode.prev = prevNode;

            newNode.next = nextNode;
            nextNode.prev = newNode;

            this.length++;
        }
    }

    public void addBack(int input, int idx) {
        if (idx >= this.length) {
            this.addLast(input);
        } else {
            Node newNode = new Node(input);
            Node prevNode = this.getNode(idx);
            Node nextNode = prevNode.next; // can be null

            prevNode.next = newNode;
            newNode.prev = prevNode;

            if (nextNode != null) {
                newNode.next = nextNode;
                nextNode.prev = newNode;
            } else {
                this.tail = newNode;
            }

            this.length++;
        }
    }

    public Integer removeFirst() {
        if (this.empty())
            return null;

        Node deleteNode = this.head;
        Integer result = deleteNode.data;
        Node newHead = deleteNode.next;

        this.head = newHead;
        if (newHead != null)
            newHead.prev = null;
        else
            this.tail = null;

        deleteNode = null;
        this.length--;

        return result;
    }

    public Integer remove(int idx) {
        if (this.empty() || idx < 0 || idx >= this.length) {
            return null;
        } else if (idx == 0) {
            return this.removeFirst();
        } else {
            Node deleteNode = this.getNode(idx);
            Integer result = deleteNode.data;
            Node prevNode = deleteNode.prev;
            Node nextNode = deleteNode.next;

            if (prevNode != null)
                prevNode.next = nextNode;
            else
                this.head = nextNode;

            if (nextNode != null)
                nextNode.prev = prevNode;
            else
                this.tail = prevNode;

            deleteNode = null;
            this.length--;

            return result;
        }
    }

    public Integer removeLast() {
        if (this.empty())
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
