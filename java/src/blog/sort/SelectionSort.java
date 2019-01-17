package blog.sort;

/*
selection sort: find smallest idx from 1 then swap 0 and 1 (time: O(n^2), space: O(1))

e.g.
num 0 1 2 3 4
---------------
    5 2 1 8 3
    1 2 5 8 3 <- 0
    1 2 5 8 3 <- 1
    1 2 3 8 5 <- 2
    1 2 3 5 8 <- 3
*/
public class SelectionSort {

    public void asc(int[] arr) {
        int idx, tmp;

        for (int i = 0; i < arr.length - 1; i++) {
            idx = i;

            // compare
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[idx])
                    idx = j;
            }

            // swap
            if (i != idx) {
                tmp = arr[i];
                arr[i] = arr[idx];
                arr[idx] = tmp;
            }
        }
    }

    public void desc(int[] arr) {
        int idx, tmp;

        for (int i = 0; i < arr.length - 1; i++) {
            idx = i;

            // search
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[idx] < arr[j])
                    idx = j;
            }

            // swap
            if (idx != i) {
                tmp = arr[i];
                arr[i]  = arr[idx];
                arr[idx] = tmp;
            }
        }
    }
}
