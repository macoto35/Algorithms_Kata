package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DoublyLinkedListTest {

    DoublyLinkedList list;

    @BeforeEach
    public void setUp() {
        this.list = new DoublyLinkedList();
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
        this.list.addFront(2, 0);
        this.list.addFront(3, 1);
        this.list.addFront(4, 2);
        this.list.addFront(5, 2);
        this.list.addFront(6, 3);

        assertEquals("2,3,5,6,4,1", this.list.toString());
    }

    @Test
    public void addBack() {
        this.list.addBack(1, 0);
        this.list.addBack(2, 1);
        this.list.addBack(3, 1);
        this.list.addBack(4, 1);

        assertEquals("1,2,4,3", this.list.toString());
    }

    private void getNodes() {
        this.list.addLast(1);
        this.list.addLast(2);
        this.list.addLast(3);
        this.list.addLast(4);
        this.list.addLast(5);
    }

    @Test
    public void removeFirst() {
        this.getNodes();

        assertEquals(1, this.list.removeFirst());
        assertEquals(2, this.list.removeFirst());
        assertEquals(3, this.list.removeFirst());
        assertEquals(4, this.list.removeFirst());
        assertEquals(5, this.list.removeFirst());
        assertNull(this.list.removeFirst());

        this.getNodes();
        this.list.removeFirst();
        this.list.removeFirst();
        this.list.addFirst(6);
        this.list.addBack(7, 2);
        this.list.removeFirst();
        this.list.addFront(8, 3);
        this.list.addLast(9);
        assertEquals("3,4,7,8,5,9", this.list.toString());
    }

    @Test
    public void remove() {
        this.getNodes();

        assertNull(this.list.remove(5));
        assertNull(this.list.remove(-1));
        assertEquals(5, this.list.remove(4));
        assertEquals(1, this.list.remove(0));
        assertEquals(3, this.list.remove(1));
        assertEquals(4, this.list.remove(1));
        assertEquals(2, this.list.remove(0));
    }

    @Test
    public void removeLast() {
        this.getNodes();

        assertEquals(5, this.list.removeLast());
        assertEquals(4, this.list.removeLast());
        assertEquals(3, this.list.removeLast());
        assertEquals(2, this.list.removeLast());
        assertEquals(1, this.list.removeLast());
        assertNull(this.list.removeLast());
    }

    @Test
    public void empty() {
        assertEquals(true, this.list.empty());

        this.list.addFirst(1);
        assertEquals(false, this.list.empty());
    }

    @Test
    public void size() {
        assertEquals(0, this.list.size());

        this.list.addBack(1, 1);
        this.list.addFirst(2);
        this.list.addLast(3);
        this.list.removeFirst();
        this.list.addFront(4, 2);
        this.list.addFirst(5);
        this.list.removeLast();
        this.list.addLast(6);
        this.list.addLast(7);
        this.list.addLast(8);
        this.list.remove(3);

        assertEquals("5,1,3,7,8", this.list.toString());
        assertEquals(5, this.list.size());
    }

    @Test
    public void get() {
        this.getNodes();

        assertNull(this.list.get(-1));
        assertEquals(1, this.list.get(0));
        assertEquals(2, this.list.get(1));
        assertEquals(3, this.list.get(2));
        assertEquals(4, this.list.get(3));
        assertEquals(5, this.list.get(4));
        assertNull(this.list.get(5));
    }

    @Test
    public void indexOf() {
        this.getNodes();

        assertEquals(0, this.list.indexOf(1));
        assertEquals(1, this.list.indexOf(2));
        assertEquals(2, this.list.indexOf(3));
        assertEquals(3, this.list.indexOf(4));
        assertEquals(4, this.list.indexOf(5));
        assertEquals(-1, this.list.indexOf(6));
    }
}