package blog.sort;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class MergeSortTest {

    MergeSort mergeSort;
    int[] a, b, expected;


    @BeforeEach
    public void setUp() {
        this.mergeSort = new MergeSort();

        this.a = new int[]{12, 59, 34, 23, 17, 61, 31, 14};
        this.b = Arrays.copyOf(a, a.length);
        this.expected = new int[]{12, 14, 17, 23, 31, 34, 59, 61};
    }

    @Test
    public void topDown() {
        this.mergeSort.topDown(this.b, this.a, 0, a.length);
        assertArrayEquals(this.expected, this.a);
    }

    @Test
    public void bottomUp() {
        this.mergeSort.bottomUp(this.b, this.a, a.length);
        assertArrayEquals(this.expected, this.a);
    }

    @Test
    public void topDownList() {
        assertArrayEquals(this.expected, this.mergeSort.topDownList(this.a, 0, a.length - 1));
    }
}