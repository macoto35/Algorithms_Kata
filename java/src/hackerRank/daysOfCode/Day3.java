package hackerRank.daysOfCode;

public class Day3 {
    public static void main(String[] args) {
        for (int n = 1; n <= 100; n++) {
            System.out.print(n);
            if (n % 2 == 1) {
                System.out.println(": Weird (odd)");
            } else {
                if (n >= 2 && n <= 5) {
                    System.out.println(": Not Weird (even, 2 ~ 5)");
                } else if (n >= 6 && n <= 20) {
                    System.out.println(": Weird (even, 6 ~ 20)");
                } else {
                    System.out.println(":  Not Weird (even, 21 ~)");
                }
            }
        }
    }
}
