package blog.sort;

import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeAll;

import static org.junit.jupiter.api.Assertions.*;

class ShellSortTest {
    static ShellSort shellSort;

    @BeforeAll
    public static void setUp() {
        shellSort = new ShellSort();
    }

    @Test
    public void myCode() {
        //int[] arr = {5, 2, 3, 8, 1};
        //int[] expected = {1, 2, 3, 5, 8};
        int[] arr = {62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28};
        int[] expected = {7, 17, 18, 25, 28, 47, 53, 62, 69, 83, 86, 95};

        shellSort.myCode(arr);

        assertArrayEquals(expected, arr);
    }

    @Test
    public void wikiCode() {
        //int[] arr = {5, 2, 3, 8, 1};
        //int[] expected = {1, 2, 3, 5, 8};
        int[] arr = {62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28};
        int[] expected = {7, 17, 18, 25, 28, 47, 53, 62, 69, 83, 86, 95};

        shellSort.wikiCode(arr);

        assertArrayEquals(expected, arr);
    }

}