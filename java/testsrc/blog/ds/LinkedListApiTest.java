package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LinkedListApiTest {
    LinkedListApi list;

    @BeforeEach
    public void setUp() {
        list = new LinkedListApi();
    }

    @Test
    public void add() {
        Integer[] expected = {4, 8, 9, 2, 1, 3, 5, 6, 7};
        assertArrayEquals(expected, list.add());
    }

    @Test
    public void remove() {
        Integer[] expected = {3, 7, 4, 5, 6, 2, 3};
        assertArrayEquals(expected, list.remove());
        assertArrayEquals(new Integer[]{}, list.removeAll());
    }

    @Test
    public void get() {
        Integer[] expected = {10, 3, 4, 5, 6, 9};
        assertArrayEquals(expected, list.get());
    }

    @Test
    public void etc() {
        Integer expected = 8;
        assertEquals(expected, list.etc());
    }

    @Test
    public void queue() {
        Integer[] expected = {4, 8, 7, 9, 9, 6};
        assertArrayEquals(expected, list.queue());
    }

    @Test
    public void stack() {
        Integer[] expected = {5, 4, 3, 2, 1};
        assertArrayEquals(expected, list.stack());
    }

    @Test
    public void descIterator() {
        Integer[] expected = {7, 6, 5, 3, 1, 2, 9, 8, 4};
        assertArrayEquals(expected, this.list.descIterator());
    }
}