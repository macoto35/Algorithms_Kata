package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LinkedLisDstTest {
    LinkedListDs list;

    @BeforeEach
    public void setUp() {
        list = new LinkedListDs();
    }

    @Test
    public void apiAdd() {
        Integer[] expected = {4, 8, 9, 2, 1, 3, 5, 6, 7};
        assertArrayEquals(expected, list.apiAdd());
    }

    @Test
    public void apiRemove() {
        Integer[] expected = {3, 7, 4, 5, 6, 2, 3};
        assertArrayEquals(expected, list.apiRemove());
        assertArrayEquals(new Integer[]{}, list.apiRemoveAll());
    }

    @Test
    public void apiGet() {
        Integer[] expected = {10, 3, 4, 5, 6, 9};
        assertArrayEquals(expected, list.apiGet());
    }

    @Test
    public void apiEtc() {
        Integer expected = 8;
        assertEquals(expected, list.apiEtc());
    }

    @Test
    public void apiQueue() {
        Integer[] expected = {4, 8, 7, 9, 9, 6};
        assertArrayEquals(expected, list.apiQueue());
    }

    @Test
    public void apiStack() {
        Integer[] expected = {5, 4, 3, 2, 1};
        assertArrayEquals(expected, list.apiStack());
    }

    @Test
    public void apiDescIterator() {
        Integer[] expected = {7, 6, 5, 3, 1, 2, 9, 8, 4};
        assertArrayEquals(expected, this.list.apiDescIterator());
    }

    public void getSimpleNode() {
        Node node = this.list.getSimpleNode();

        assertEquals(1, node.data);
        assertEquals(2, node.next.data);
    }
}