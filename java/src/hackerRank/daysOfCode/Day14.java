package hackerRank.daysOfCode;

import java.util.*;
import java.util.stream.*;

/*
- Scope: region of the program to which an identifier applies.
*/
public class Day14 {

    public class Difference {
        private int[] elements;

        public int maximumDifference;

        public Difference(int[] elements) {
            this.elements = elements;
        }

        public void computeDifference() {
            int min = 100, max = 0;
            for (int i : elements) {
                if (i < min)
                    min = i;
                if (i > max)
                    max = i;
            }

            this.maximumDifference = max - min;
        }
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String s = scanner.nextLine();

        Difference diff = new Difference(Stream.of(s.split(" ")).mapToInt(Integer::parseInt).toArray());
        diff.computeDifference();

        System.out.println(diff.maximumDifference);

        scanner.close();
    }

    public static void main(String[] args) {
        Day14 day14 = new Day14();
        day14.run();
    }
}
