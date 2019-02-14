package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.lang.ArrayIndexOutOfBoundsException;

import static org.junit.jupiter.api.Assertions.*;

class QueueArrayTest {

    private QueueArray queue;

    @BeforeEach
    public void setUp() {
        this.queue = new QueueArray();
    }

    @Test
    public void enqueue() {
        for (int i = 1; i < 6; i++)
            this.queue.enqueue(i);

        assertEquals("1,2,3,4,5", this.queue.toString());

        assertThrows(ArrayIndexOutOfBoundsException.class, () -> this.queue.enqueue(6));
    }

    @Test
    public void dequeue1() {
        this.enqueue();

        for (int i = 1; i < 6; i++)
            assertEquals(i, this.queue.dequeue());
    }

    public void testData() {
        this.queue.enqueue(1);
        this.queue.enqueue(2);
        this.queue.enqueue(3);
        assertEquals(1, this.queue.dequeue());
        assertEquals(2, this.queue.dequeue());
        this.queue.enqueue(4);
        this.queue.enqueue(5);
        this.queue.enqueue(6);
        this.queue.enqueue(7);
    }

    @Test
    public void dequeue2() {
        this.testData();
        assertThrows(IndexOutOfBoundsException.class, () -> this.queue.enqueue(8));
    }

    @Test
    public void dequeue3() {
        this.testData();
        assertEquals(3, this.queue.dequeue());
        this.queue.enqueue(8);
    }
}