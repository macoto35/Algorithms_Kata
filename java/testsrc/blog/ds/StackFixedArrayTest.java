package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StackFixedArrayTest {

    StackFixedArray stack;

    @BeforeEach
    public void setUp() {
        stack = new StackFixedArray();
    }

    @Test
    public void push() {
        for (int i = 1; i < 5; i++)
            this.stack.push(i);
        assertEquals("1,2,3,4", this.stack.toString());

        assertThrows(ArrayIndexOutOfBoundsException.class, () -> this.stack.push(5));
    }

    @Test
    public void pop() {
        for (int i = 1; i < 5; i++)
            this.stack.push(i);

        for (int i = 4; i >= 1; i--)
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

        this.stack.push(2);
        assertEquals(2, this.stack.peek());
    }

    @Test
    public void search() {
        for(int i = 1; i < 5; i++)
            this.stack.push(i);

        for (int i = 0; i < 4; i++)
            assertEquals(i, this.stack.search(i + 1));
        assertEquals(-1, this.stack.search(5));
    }
}