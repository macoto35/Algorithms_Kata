package hackerRank.daysOfCode;

import java.util.*;

/*
- Stack: LIFO. Peek(return top object without removing)/Push(add object to the top)/Pop(Remove object at the top and return) operators. java.util.Stack class.
- Queue: FIFO. Enqueue(add object to the back)/Dequeue(remove object at the head and return) operators. java.util.Queue interface, LinkedList class (add: enqueue, remove: dequeue).
*/
public class Day18 {
    Stack<Character> stack = new Stack<>();
    Queue<Character> queue = new LinkedList<>();

    public void pushCharacter(char c) {
        stack.push(c);
    }

    public char popCharacter() {
        return stack.pop();
    }

    public void enqueueCharacter(char c) {
        queue.add(c);
    }

    public char dequeueCharacter() {
        return queue.remove();
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        for (char c : s.toCharArray()) {
            this.pushCharacter(c);
            this.enqueueCharacter(c);
        }

        boolean isPalindrome = true;
        for (int i = 0; i < s.length() / 2; i++) {
            if (this.popCharacter() != this.dequeueCharacter()) {
                isPalindrome = false;
                break;
            }
        }

        System.out.println("The word, " + s + ", is" + (!isPalindrome? " not " : " ") + "a palindrome.");
        scanner.close();
    }

    public static void main(String[] args) {
        Day18 day18 = new Day18();
        day18.run();
    }
}
