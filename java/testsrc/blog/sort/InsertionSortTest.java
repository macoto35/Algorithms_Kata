package blog.sort;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class InsertionSortTest {

    @Test
    void insertionSort() {
        InsertionSort insertionSort = new InsertionSort();
        int[] arr = {5,2,1,8,3,3};

        int[] ascExpected = {1,2,3,3,5,8};
        insertionSort.asc(arr);
        assertArrayEquals(ascExpected, arr);

        int[] descExpected = {8,5,3,3,2,1};
        insertionSort.desc(arr);
        assertArrayEquals(descExpected, arr);
    }
}