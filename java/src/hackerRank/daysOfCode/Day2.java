package hackerRank.daysOfCode;

import java.util.*;

/*
- Arithmetic Operator
    +, -, *, /, %, ++, --
- Relational Operator
    ==, !=, <, >, >=, <=
- Bitwise Operator
    &, |, ^(xor), ~(not), <<, >>, >>>(zero fill right shift)
- Logical Operator
    &&, ||, !
- Assignment Operator
    =, +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
- Conditional Operator / Ternary Operator
    (condition) ? (value if true) : (value if false)
- Instanceof Operator
    String s = "abc";
    boolean result = s instanceof String;

Precedence:
a++, a--
++a, --a, +a, -a, ~, !
*, /, %
+, -
<<, >>, >>>
<, >, <=, >=, instanceof
==, !=
&
^
|
&&
||
?:
=, +=, -=, *=, /=, %=, ^=, |=, <<=, >>=, >>>=
*/
public class Day2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double mealCost = scanner.nextDouble();
        int tipPercent = scanner.nextInt();
        int taxPercent = scanner.nextInt();
        scanner.close();

        System.out.println(Math.round(mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100));
    }
}
