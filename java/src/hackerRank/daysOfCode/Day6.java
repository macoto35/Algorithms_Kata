package hackerRank.daysOfCode;

import java.util.*;

public class Day6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < t; i++) {
            String s = scanner.nextLine();
            char[] chars = s.toCharArray();

            String even = "";
            String odd = "";
            for (int j = 0; j < chars.length; j++) {
                if (j % 2 == 0)
                    even += chars[j];
                else
                    odd += chars[j];
            }
            System.out.println(even + " " + odd);
        }
        scanner.close();
    }
}
