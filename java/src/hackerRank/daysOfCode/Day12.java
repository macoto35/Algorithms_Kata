package hackerRank.daysOfCode;

import java.util.stream.*;
import java.util.*;

/*
- Inheritance: Establish a hierarchy for the class.
               A class inherits from superclass is called a subclass. Subclass inherits methods and variables from a superclass,
               and it can declare new fields and methods (as well as override superclass method)
- Subclass(derived class, extended class, child class): ClassB(subclass) extends ClassA(superclass). only single inheritance.
                                                        A constructor initialized an instance of a class, they are never inherited.
                                                        However, the subclass must call a superclass constructor as it is an extension of a superclass object.
                                                        explicit call to super(...) or implicit call to the superclass' default constructor
- Overriding Method: @Override annotation
*/
public class Day12 {
    public class Person {
        private String firstName;

        private String lastName;

        private int idNumber;

        public Person() {}

        public Person(String firstName, String lastName, int idNumber) {
            this.firstName = firstName;
            this.lastName = lastName;
            this.idNumber = idNumber;
        }

        public void printPerson() {
            System.out.println("Name: " + this.lastName + "," + this.firstName);
            System.out.println("ID: " + this.idNumber);
        }
    }

    public class Student extends Person {
        private int[] scores;

        public Student() {}

        public Student(int[] scores) {
            this.scores = scores;
        }

        String calculate() {
            int result = IntStream.of(this.scores).sum() / this.scores.length;

            if (result >= 90 && result <= 100)
                return "O";
            else if (result >= 80 && result < 90)
                return "E";
            else if (result >= 70 && result < 80)
                return "A";
            else if (result >= 55 && result < 70)
                return "P";
            else if (result >= 40 && result < 55)
                return "D";
            else
                return "T";
        }
    }

    void run() {
        Scanner scanner = new Scanner(System.in);
        String[] info = scanner.nextLine().split(" ");
        scanner.nextLine();
        String[] score = scanner.nextLine().split(" ");

        Person p = new Person(info[0], info[1], Integer.parseInt(info[2]));
        Student s = new Student(Stream.of(score).mapToInt(Integer::parseInt).toArray());

        p.printPerson();
        System.out.println("Grade: " + s.calculate());
    }

    public static void main(String[] args) {
        Day12 day12 = new Day12();
        day12.run();
    }
}
