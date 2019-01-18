package blog.sort;

import java.util.Arrays;

/*
- using gap sequence -> do insertion or bubble sort (worst case time: O(n^2) / O(n log^2n), best case time: O(n log n), space: O(1)  )
- recommand gap sequence: 2^n - 1
*/
public class ShellSort {
    public void myCode(int[] arr) {
        int gap = arr.length;
        int tmp, j;

        //System.out.println("----------------------------------------------> my code");
        //this.print(arr, 0, 0, 0);

         do {
            gap = gap / 3 + 1;
            for (int st = 0; st < gap; st++)

                // insertion sort
                for (int i = st + gap; i < arr.length; i += gap) {
                    tmp = arr[i];
                    j = i - gap;

                    while (j >= 0 && arr[j] > tmp) {
                        arr[j + gap] = arr[j];
                        //this.print(arr, st, i, j);
                        j -= gap;
                    }

                    arr[j + gap] = tmp;
                    //this.print(arr, st, i, j);
                }
        } while(gap > 1);
    }

    public void wikiCode(int[] arr) {
        //System.out.println("----------------------------------------------> wiki code");
        //this.print(arr, 0, 0, 0);

        int gap = arr.length;
        int tmp, j;

        do {
            gap = gap / 3 + 1;

            for (int i = gap; i < arr.length; i++) {
                tmp = arr[i];
                for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap) {
                    arr[j] = arr[j - gap];
                    //this.print(arr, gap, i, j);
                }
                arr[j] = tmp;
                //this.print(arr, gap, i, j);
            }
        } while(gap > 1);
    }

    private void print(int[] arr, int gap, int i, int j) {
        StringBuffer sb = new StringBuffer();
        Arrays.stream(arr).forEach((val) -> sb.append(val + " "));

        System.out.println("gap = " + gap + ", i = " + i + ", j = " + j + ", arr = " + sb.toString());
    }
}
