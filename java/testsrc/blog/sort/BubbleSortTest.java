package blog.sort;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class BubbleSortTest {
    BubbleSort bubbleSort;

    @BeforeEach
    public void setUp() {
        bubbleSort = new BubbleSort();
    }

    @Test
    public void bubbleSort() {
        int[] arr = {5,2,1,8,3,3};

        int[] ascExpected = {1,2,3,3,5,8};
        bubbleSort.asc(arr);
        assertArrayEquals(ascExpected, arr);

        int[] descExpected = {8,5,3,3,2,1};
        bubbleSort.desc(arr);
        assertArrayEquals(descExpected, arr);
    }

    @Test
    public void enhancedBubbleSort() {
        int[] arr = {6,7,8,1,2,3,4,5};
        int[] expected = {1,2,3,4,5,6,7,8};

        bubbleSort.enhanced(arr);

        assertArrayEquals(expected, arr);
    }

}