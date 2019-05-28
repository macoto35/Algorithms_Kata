package hackerRank.daysOfCode;

import java.util.*;

/*
- Data Structure: a way of organizing data that enables efficient storage, retrieval, and use.
- Array: same type. contiguous memory. indexed from 0 to n-1.
*/
public class Day7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = scanner.nextInt();

        for (int i = n - 1; i >= 0; i--)
            System.out.print(arr[i] + " ");

        scanner.close();
    }
}
