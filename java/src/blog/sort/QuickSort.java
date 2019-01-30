package blog.sort;

import java.util.Random;

public class QuickSort {
    public void lomoto(int[] arr, int left, int right) {
        if (left >= right)
            return;

        int[] result = this.lomotoPartition(arr, left, right);

        this.lomoto(arr, left, result[0]);
        this.lomoto(arr, result[1] + 1, right);
    }

    private int[] lomotoPartition(int[] arr, int left, int right) {
        int pivot = this.getRandomPivot(arr, left, right);
        int j, k;
        j = k = left;

        for (int i = left + 1; i < right; i++) {
            if (arr[i] < pivot) {
                k++;
                this.swap(arr, i, k);
                this.swap(arr, j, k);
                j++;
            } else if (arr[i] == pivot) {
                k++;
                this.swap(arr, i, k);
            }
        }

        return new int[]{j, k};
    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private int getRandomPivot(int[] arr, int left, int right) {
        Random r = new Random();
        int i = r.ints(left, right).findFirst().getAsInt();
        this.swap(arr, left, i);

        return arr[left];
    }

    public void hoare(int[] arr, int left, int right) {
        if (left >= right)
            return;

        int j = this.hoarePartition(arr, left, right);

        this.hoare(arr, left, j);
        this.hoare(arr, j + 1, right);
    }

    public int hoarePartition(int[] arr, int left, int right) {
        int pivot = this.getRandomPivot(arr, left, right);
        int i = left - 1;
        int j = right + 1;

        while (true) {
            do {
                i++;
            } while(i < right && arr[i] < pivot);

            do {
                j--;
            } while(j > left && arr[j] > pivot);

            if (i >= j)
                return j;

            this.swap(arr, i, j);
        }
    }
}
