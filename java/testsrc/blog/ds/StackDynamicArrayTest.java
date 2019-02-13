package blog.ds;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;

import static org.junit.jupiter.api.Assertions.*;

class StackDynamicArrayTest {

    StackDynamicArray stack;

    @BeforeEach
    public void setUp() {
        this.stack = new StackDynamicArray();
    }

    @Test
    public void push() {
        for (int i = 1; i < 6; i++)
            this.stack.push(i);

        assertEquals("1,2,3,4,5,0,0,0", this.stack.toString());
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

        for (int i = 0; i < 5; i++)
            assertEquals(i, this.stack.search(i+1));
        assertEquals(-1, this.stack.search(6));
    }
}