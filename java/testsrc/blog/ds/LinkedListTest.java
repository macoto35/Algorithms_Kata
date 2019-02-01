package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LinkedListTest {

    LinkedList list;

    @BeforeEach
    public void setUp() {
        this.list = new LinkedList();
    }

    @Test
    public void node() {
        Node second = new Node(2, null);
        Node first = new Node(1, second);

        assertEquals(1, first.data);
        assertEquals(2, first.next.data);
    }

    @Test
    public void addFirst() {
        this.list.addFirst(1);
        this.list.addFirst(2);
        this.list.addFirst(3);
        this.list.addFirst(4);

        assertEquals("4,3,2,1", this.list.toString());
    }

    @Test
    public void addLast() {
        this.list.addLast(1);
        this.list.addLast(2);
        this.list.addLast(3);
        this.list.addLast(4);

        assertEquals("1,2,3,4", this.list.toString());
    }

    @Test
    public void addFront() {
        this.list.addFront(1, 0);
        this.list.addFront(2, 1);
        this.list.addFront(3, 1);
        this.list.addFront(4, 2);

        assertEquals("1,3,4,2", this.list.toString());
    }

    @Test
    public void addBack() {
        this.list.addBack(1, 0);
        this.list.addBack(2, 1);
        this.list.addBack(3, 1);
        this.list.addBack(4, 1);

        assertEquals("1,2,4,3", this.list.toString());
    }
}