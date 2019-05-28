package hackerRank.daysOfCode;

import java.util.*;
import java.util.stream.*;

public class Day17 {
    public class Calculator {
        public int power(int n, int p) throws Exception {
            if (n < 0 || p < 0)
                throw new Exception("n and p should be non-negative.");

            return (int) Math.pow(n, p);
        }
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Calculator c = new Calculator();

        for (int i = 0; i < n; i++) {
            int[] arr = Stream.of(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            try {
                System.out.println(c.power(arr[0], arr[1]));
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }

        scanner.close();
    }

    public static void main(String[] args) {
        Day17 day17 = new Day17();
        day17.run();
    }
}
