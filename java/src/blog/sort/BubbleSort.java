package blog.sort;

public class BubbleSort {

    public void asc(int[] arr) {
        boolean swapped = true;
        System.out.println("enter asc: ");

        for(int i = arr.length - 1; i > 0 && swapped; i--) {
            System.out.println("outer for, idx = " + i);
            swapped = false;

            for (int j = 0; j < i; j++) {
                System.out.println("inner for, idx = " + j);
                if (arr[j] > arr[j+1]) {
                    this.swap(arr, j, j+1);
                    swapped = true;
                }
            }
        }
    }

    public void desc(int[] arr) {
        boolean swapped = true;

        for (int i = arr.length - 1; i > 0 && swapped; i--) {
            swapped = false;

            for(int j = 0; j < i; j++) {
                if (arr[j] < arr[j+1]) {
                    this.swap(arr, j, j+1);
                    swapped = true;
                }
            }
        }
    }

    public void enhanced(int[] arr) {
        int i = arr.length - 1, newi;
        System.out.println("enter enhanced: ");

        while (i > 0) {
            System.out.println("outer for, idx = " + i);
            newi = 0;
            for (int j = 0; j < i; j++) {
                System.out.println("inner for, idx = " + j);
                if (arr[j] > arr[j+1]) {
                    this.swap(arr, j, j+1);
                    newi = j;
                }
            }
            i = newi;
        }
    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void main(String[] args) {
        int[] arr1 = {6, 8, 1, 3, 7, 2, 9, 5, 4};
        int[] arr2 = new int[9];
        System.arraycopy(arr1, 0, arr2, 0, arr1.length);

        BubbleSort bs = new BubbleSort();
        bs.asc(arr1);

        bs.enhanced(arr2);
    }
}
