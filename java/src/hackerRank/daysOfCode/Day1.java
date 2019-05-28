package hackerRank.daysOfCode;

import java.util.*;

/*
primitive Data Type
byte: 1 byte
short: 2 bytes
character: 2 byte
int: 4 bytes
long: 8 bytes
float: 4 bytes
double: 8 bytes
boolean: true/false
*/
public class Day1 {
    public static void main(String[] args) {
        int i = 4;
        double d = 4.0;
        String s = "HackerRank ";

        Scanner scanner = new Scanner(System.in);
        int ni = scanner.nextInt();
        double nd = scanner.nextDouble();
        scanner.nextLine();
        String ns = scanner.nextLine();
        scanner.close();

        System.out.println(i + ni);
        System.out.println(d + nd);
        System.out.println(s + ns);

        /*double a = 123.4567;
        System.out.println(Math.round(a * 10) / 10.0);*/
    }
}
