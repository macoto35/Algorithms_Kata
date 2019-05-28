package hackerRank.daysOfCode;

import java.util.*;

/*
- Think Simpler proble, Find base case
- Don't think step by step
- Looking at intermediate step, what is next step to perform?
*/
public class Day9 {
    void fibonacci(double result, int n) {
        if (n == 0) {
            System.out.println(result);
            return;
        }
        this.fibonacci(result * n, n - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Day9 day9 = new Day9();
        day9.fibonacci(1, n);

        scanner.close();
    }
}
