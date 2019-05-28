package hackerRank.daysOfCode;

import java.util.*;

/*
- Radix(Base): number n having radix r = (n)r
- Binary -> Decimal:
  (840)10 = (8 * 10**2) + (4 * 10**1) + (0 * 10**0) = 800 + 40 + 0 = 840
  Dk-1Dk-2...D2D1D0 = each Di * 2**i where 0 <= i <= k-1, i = k-1 is the most significant bit, and i = 0 is the least significant bit
  (1011)2 = (1 * 2**3) + (0 * 2**2) + (1 * 2**1) + (1 * 2**0) = 8 + 0 + 2 + 1 = (11)10 -> int i = Integer.parseInt("1011"), 2)
- Decimal -> Binary:
  (4)10 = (100)2 -> String b = Inreger.toBinaryString(4)
  4 / 2 = 2 ... 0
  2 / 2 = 1 ... 0
  1 / 2 = 0 ... 1 (read from bottom up)
*/
public class Day10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int i = scanner.nextInt();
        String b = Integer.toBinaryString(i);

        int result = 0, maxNum = 0;
        for (char c : b.toCharArray()) {
            if (c == '1') {
                maxNum++;
            } else {
                if (maxNum > result)
                    result = maxNum;
                maxNum = 0;
            }
        }

        System.out.println(result);

        scanner.close();
    }
}
