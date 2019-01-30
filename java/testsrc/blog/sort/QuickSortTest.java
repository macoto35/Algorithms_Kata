package blog.sort;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Disabled;

import static org.junit.jupiter.api.Assertions.*;

class QuickSortTest {

    QuickSort quickSort;
    int[] arr1, arr2, arr1Expected, arr2Expected;

    @BeforeEach
    public void setUp() {
        this.quickSort = new QuickSort();

        this.arr1 = new int[]{15, 20, 13, 30, 10, 25, 3, 24};
        this.arr1Expected = new int[] {3, 10, 13, 15, 20, 24, 25, 30};

        this.arr2 = new int[]{5, 5, 5, 5, 5};
        this.arr2Expected = new int[]{5, 5, 5, 5, 5};
    }

    @Test
    public void quickSortLomoto() {
        this.quickSort.lomoto(arr1, 0, arr1.length);
        assertArrayEquals(arr1Expected, arr1);

        this.quickSort.lomoto(arr2, 0, arr2.length);
        assertArrayEquals(arr2Expected, arr2);
    }

    @Disabled
    @Test
    public void quickSortHoare() {
        this.quickSort.hoare(arr1, 0, arr1.length - 1);
        assertArrayEquals(arr1Expected, arr1);

        this.quickSort.hoare(arr2, 0, arr2.length - 1);
        assertArrayEquals(arr2Expected, arr2);
    }
}