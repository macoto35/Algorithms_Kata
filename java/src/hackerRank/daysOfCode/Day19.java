package hackerRank.daysOfCode;

import java.util.*;

/*
Interface: Abstraction is the separation between what something does and how it's accomplished.
        Interface is a collection of abstract methods and constants. Form a common set of base rules/specifications for those classes that implement it.
        Interface cannot be instantiated and must be implemented by a class.
        */
public class Day19 {
    public interface AdvancedArithmetic {
        public int divisorSum(int n);
    }

    public class Calculator implements AdvancedArithmetic {
        public int divisorSum(int n) {
            if (n == 1)
                return 1;

            int result = 1 + n;
            int max = n;
            for (int min = 2; min < max; min++) {
                if (n % min == 0) {
                    max = n / min;

                    if (min == max)
                        result += min;
                    else
                        result += min + max;
                }
            }

            return result;
        }
    }

    public void run() {
        Calculator c = new Calculator();
        String interfaceName = c.getClass().getInterfaces()[0].getSimpleName();

        for (int i = 1; i <= 1000; i++)
            System.out.println("I implemented, " + interfaceName + ": " + i + " / " + c.divisorSum(i));
    }

    public static void main(String[] args) {
        Day19 day19 = new Day19();
        day19.run();
    }
}
