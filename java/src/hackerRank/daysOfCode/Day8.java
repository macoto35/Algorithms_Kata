package hackerRank.daysOfCode;

import java.util.*;

/*
- Map (HashMap, LinkedHashMap, treeMap): (key, value) pairs. key and value must be objects and not primitives.
*/
public class Day8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Map<String, String> phoneBook = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] arr = scanner.nextLine().split(" ");
            phoneBook.put(arr[0], arr[1]);
        }

        while (true) {
            String name = scanner.nextLine();

            if (name.isEmpty())
                break;

            if (phoneBook.containsKey(name))
                System.out.println(name + "=" + phoneBook.get(name));
            else
                System.out.println("Not found");
        }

        scanner.close();
    }
}
