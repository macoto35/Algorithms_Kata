package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StackLinkedListTest {

    StackLinkedList stack;

    @BeforeEach
    public void setUp() {
        this.stack = new StackLinkedList();
    }

    @Test
    public void push() {
        for (int i = 1; i < 6; i++)
            this.stack.push(i);
        assertEquals("5,4,3,2,1", this.stack.toString());
    }

    @Test
    public void pop() {
        this.push();

        for (int i = 5; i > 0; i--)
            assertEquals(i, this.stack.pop());
        assertNull(this.stack.pop());
    }

    @Test
    public void empty() {
        assertEquals(true, this.stack.empty());

        this.stack.push(1);
        assertEquals(false, this.stack.empty());
    }

    @Test
    public void peek() {
        assertNull(this.stack.peek());

        for (int i = 1; i < 6; i++) {
            this.stack.push(i);
            assertEquals(i, this.stack.peek());
        }
    }

    @Test
    public void search() {
        this.push();

        int eIdx = 4;
        for (int i = 1; i < 6; i++)
            assertEquals(eIdx--, this.stack.search(i));

        assertEquals(-1, this.stack.search(6));
    }
}