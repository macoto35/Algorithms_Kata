package hackerRank.daysOfCode;

import java.util.*;
import java.util.regex.*;

/*
T = 1, F = 0

- Bitwise AND(&):
    1 & 1 = 1
    1 & 0 = 0
    0 & 1 = 0
    0 & 0 = 0
- Bitwise OR(|):
    1 | 1 = 1
    1 | 0 = 1
    0 | 1 = 1
    0 | 0 = 0
- Bitwise Exclusive OR or XOR(^):
    1 ^ 1 = 0
    1 ^ 0 = 1
    0 ^ 1 = 1
    0 ^ 0 = 0
*/
public class Day29 {
    public void binaryString(String s, int i) {
        for (byte b : s.getBytes()) {
            System.out.print(Integer.toBinaryString(b) + " ");
        }

        System.out.println(Integer.toBinaryString(i) + "\n");
    }

    public void binaryStringOr(String s, int i) {
        for (byte b : s.getBytes()) {
            int tmp = b | i;
            System.out.println( Integer.toBinaryString(b) + " OR " + Integer.toBinaryString(i) + " = " + Integer.toBinaryString(tmp) + " = " + tmp );
        }
        System.out.println();
    }

    public void binaryStringXor(String s, int i) {
        for (byte b : s.getBytes()) {
            int tmp = b ^ i;
            System.out.println( Integer.toBinaryString(b) + " XOR " + Integer.toBinaryString(i) + " = " + Integer.toBinaryString(tmp) + " = " + tmp );
        }
        System.out.println();
    }

    public int findMaxAndBruteForce(int end, int threshold) {
        //Scanner scanner = new Scanner(System.in);
        //int t = scanner.nextInt();

        //for (int i = 0; i < t; i++) {
            //int end = scanner.nextInt();
            //int threshold = scanner.nextInt();
            int max = 0;

            for (int j = 1; j < end; j++) {
                for (int k = j + 1; k <= end; k++) {
                    int val = j & k;
                    // System.out.println(j + " & " + k + " = " + val);

                    if (val > max && val <threshold)
                        max = val;
                }
            }

            //System.out.print(end + " " + threshold + " = " + max);
            return max;
        //}

        //scanner.close();
    }

    public int findMaxAnd(int end, int threshold) {
        //Scanner scanner = new Scanner(System.in);
        //int t = scanner.nextInt();

        //for (int i = 0; i < t; i++) {
            //int end = scanner.nextInt();
            //int threshold = scanner.nextInt();

            int max = (threshold - 1 | threshold) <= end ? threshold - 1 : threshold - 2;
            //System.out.println(", " + end + " " + threshold + " = " + max);
            return max;
        //}

        //scanner.close();
    }

    public static void main(String[] args) {
        String s = "HackerRank";
        int i = 8675309;

        Day29 day29 = new Day29();
        /*day29.binaryString(s, i);
        day29.binaryStringOr(s, i);
        day29.binaryStringXor(s, i);*/

        int result1 = 0, result2 = 0;
        for (int k = 2; k <= 100; k++) {
            for (int n = k; n <= 100; n++) {
                result1 = day29.findMaxAndBruteForce(n, k);
                result2 = day29.findMaxAnd(n, k);

                if (result1 != result2) {
                    System.out.println("end: " + n + ", threshold: " + k  + " = "+ result1 + " / " + result2 + "ERROR!");
                    break;
                }
            }
        }
    }
}