package hackerRank.daysOfCode;

import java.util.*;

public class Day20 {
    public static int bubbleSort1(int[] arr) {
        int n = arr.length;
        int allNumOfSwap = 0;

        for (int i = 0; i < n; i++) {
            int numOfSwap = 0;
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                    numOfSwap++;
                }
            }
            if (numOfSwap == 0)
                break;
            allNumOfSwap += numOfSwap;
        }

        return allNumOfSwap;
    }

    public static int bubbleSort2(int[] arr) {
        int lastSwapIdx = arr.length - 1;
        int allNumOfSwap = 0;

        while (lastSwapIdx > 0) {
            int swapIdx = 0, swapCnt = 0;

            for (int i = 0; i < lastSwapIdx; i++) {
                if (arr[i] > arr[i+1]) {
                    int tmp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = tmp;

                    swapIdx = i;
                    swapCnt++;
                }
            }

            lastSwapIdx = swapIdx;
            allNumOfSwap += swapCnt;
        }


        return allNumOfSwap;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        for (int i = 0; i < n; i++) {
            arr1[i] = scanner.nextInt();
            arr2[i] = arr1[i];
        }

        int numSwaps1 = bubbleSort1(arr1);
        int numSwaps2 = bubbleSort1(arr2);
        System.out.println("Array is sorted in " + numSwaps1 + "/" + numSwaps2 + " swaps.");
        System.out.println("First Element: " + arr1[0] + "/" + arr2[0]);
        System.out.println("Last Element: " + arr1[n - 1] + "/" + arr2[n - 1]);

        scanner.close();
    }
}
