package blog.sort;

/*
insertion sort: <=x | x | >x (worst time: O(n2^), best time: O(n), worst space: O(1))

e.g.
num 0 1 2 3 4
-------------
    5 2 1 8 3 <- init
    2 5 1 8 3 <- 1
    1 2 5 8 3 <- 2
    1 2 5 8 3 <- 3
    1 2 3 5 8 <- 4
*/
public class InsertionSort {

    public void asc(int[] arr) {
        int tmp, j;

        for (int i = 1; i < arr.length; i++) {
            tmp = arr[i];
            j = i - 1;

            while(j >= 0 && arr[j] > tmp) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = tmp;
        }
    }

    public void desc(int[] arr) {
        int tmp, j;
        for (int i = 1; i < arr.length; i++) {
            tmp = arr[i];
            j = i - 1;

            while(j >= 0 && arr[j] < tmp) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = tmp;
        }
    }
}
