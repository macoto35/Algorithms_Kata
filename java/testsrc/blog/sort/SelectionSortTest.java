package blog.sort;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class SelectionSortTest {

    @Test
    public void selectionSort() {
        SelectionSort selectionSort = new SelectionSort();

        int[] arr = {5, 2, 1, 8, 3};

        int[] ascExpected = {1, 2, 3, 5, 8};
        selectionSort.asc(arr);
        assertArrayEquals(ascExpected, arr);

        int[] descExpected = {8, 5, 3, 2, 1};
        selectionSort.desc(arr);
        assertArrayEquals(descExpected, arr);
    }
}
