package hackerRank.daysOfCode;

import java.util.*;

public class Day25 {
    public static void isPrime(int n) {
        if (n <= 2 || n % 2 == 0) {
            System.out.println("Not Prime");
            return;
        }

        int numOfcheck = 0;
        int max = n / 2;
        for (int i = 3; i < max; i = i+2) {
            if (n % i == 0) {
                System.out.println("Not Prime. (" + numOfcheck + ")");
                return;
            }
            numOfcheck++;
            max = n / i;
        }
        /*for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                System.out.println("Not Prime. (" + numOfcheck + ")");
                return;
            }
            numOfcheck++;
        }*/

        System.out.println("Prime (" + numOfcheck + "/" + max + ")");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for (int i = 0; i < t; i++)
            isPrime(scanner.nextInt());

        scanner.close();
    }
}



