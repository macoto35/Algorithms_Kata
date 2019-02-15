package blog.ds;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class QueueLinkedListTest {

    QueueLinkedList queue;

    @BeforeEach
    public void setUp() {
        this.queue = new QueueLinkedList();
    }

    @Test
    public void testAll() {
        for (int i = 1; i <= 10; i++)
            this.queue.enqueue(i);

        assertEquals("1,2,3,4,5,6,7,8,9,10", this.queue.toString());

        for (int i = 1; i <= 10; i++)
            assertEquals(i, this.queue.dequeue());

        assertNull(this.queue.dequeue());
    }
}