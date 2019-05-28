package hackerRank.daysOfCode;

import java.util.*;
import java.util.stream.*;
import java.time.*;
import java.time.temporal.ChronoUnit;

public class Day26 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] rd = Stream.of(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] ed = Stream.of(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        scanner.close();

        LocalDate returnDate = LocalDate.of(rd[2], rd[1], rd[0]);
        LocalDate expectedDate = LocalDate.of(ed[2], ed[1], ed[0]);

        if (returnDate.isBefore(expectedDate) || returnDate.isEqual(expectedDate)) {
            System.out.println(0);
        } else if (returnDate.getYear() != expectedDate.getYear()) {
            System.out.println(10000);
        } else if (returnDate.getMonth() != expectedDate.getMonth()) {
            System.out.println(500 * ChronoUnit.MONTHS.between(expectedDate, returnDate));
        } else {
            System.out.println(15 * ChronoUnit.DAYS.between(expectedDate, returnDate));
        }
    }
}
