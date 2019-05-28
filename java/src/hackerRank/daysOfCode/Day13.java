package hackerRank.daysOfCode;

import java.util.*;

/*
- Abstraction: separation between what a class does and how it's accomplished.
- Abstract Class: abstract methods + defined methods
                  cannot instantiated (cannot create a new instance of it) - only meant to server as a base or blueprint for connecting the subclasses that inherit it.
                  abstract method in superclass must be implemented by its subclasses (unless the subclass is also abstract)
*/
public class Day13 {
    public abstract class Book {
        protected String title;

        protected String author;

        public Book(String title, String author) {
            this.title = title;
            this.author = author;
        }

        abstract public void display();
    }

    public class MyBook extends Book{
        private int price;

        public MyBook(String title, String author, int price) {
            super(title, author);
            this.price = price;
        }

        public void display() {
            System.out.println("Title: " + this.title);
            System.out.println("Author: " + this.author);
            System.out.println("Price: " + this.price);
        }
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        String title = scanner.nextLine();
        String author = scanner.nextLine();
        int price = scanner.nextInt();

        Book book = new MyBook(title, author, price);
        book.display();
    }

    public static void main(String[] args) {
        Day13 day13 = new Day13();
        day13.run();
    }
}
