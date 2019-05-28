package hackerRank.daysOfCode;

import java.util.*;

/*
- object: Any entity has state and behaviour. Instance of class.
- class: Blueprint. Collection of objects. Logical entity. (class/static variable and instance variable)
- constructor: create an instance of a class. A constructor with no parameter (default constructor). A constructor takes oen or more parameters. (overloaded)
- method: A sort of named procedure associated with a class that performs a predefined action.
- parameter: int methodOne(int x), int x is a parameter
- argument: actual value of parameter. methodOne(5), 5 is an argument
*/
public class Day4 {

    public class Person {
        private int age;

        public Person(int initialAge) {
            if (initialAge > 0) {
                this.age = initialAge;
            } else {
                this.age = 0;
                System.out.println("Age is not valid, setting age to 0.");
            }
        }

        public void yearPasses() {
            this.age += 1;
        }

        public void amIOld() {
            if (this.age < 13) {
                System.out.println("You are young.");
            } else if (this.age >= 13 && this.age < 18) {
                System.out.println("You are a teenager.");
            } else {
                System.out.println("You are old.");
            }
        }
    }

    void main(int age) {
        Person p = new Person(age);
        p.amIOld();
        for (int j = 0; j < 3; j++)
            p.yearPasses();
        p.amIOld();
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int age = scanner.nextInt();

            Day4 d = new Day4();
            d.main(age);
        }

        scanner.close();
    }
}
