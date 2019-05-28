package hackerRank.daysOfCode;

import java.util.*;
import java.util.regex.*;

/*
- Regular Expressions: Add a level of abstraction to strings that makes it easier to search and manipulate text.
[] - specifiy the what you'd like your expression to match within square brackets
predefined - \ followed by a letter. (\d: digits 0-9, \D: non-digits, \s: space, \p{Punct}: punctuation)
. - any character
+ - one or more instances of the previous character
* - zero or more instance of the previous character
^ - first / not (if it is inside [])
$ - end
*/
public class Day28 {
    public class AlphabeticOrderCompare implements Comparator<String> {
        public int compare(String s1, String s2) {
            return s1.compareTo(s2);
        }
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<String> names = new ArrayList<>();
        Pattern p = Pattern.compile("@gmail.com");
        for (int i = 0; i < n; i++) {
            String[] s = scanner.nextLine().split(" ");

            if ( p.matcher(s[1]).find() )
                names.add(s[0]);
        }

        Collections.sort(names, new AlphabeticOrderCompare());
        System.out.println(names);

        scanner.close();
    }

    public static void main(String[] args) {
        Day28 day28 = new Day28();
        day28.run();
    }
}
