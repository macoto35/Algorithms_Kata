package hackerRank.daysOfCode;

import java.util.*;
import java.util.stream.Stream;

/*
- 2 X 4 matrix (2D array)
  int rowSize = 2;
  int colSize = 4;
  int[][] myArray = new int[rowSize][colSize];

  (0, 1) (0, 2) (0, 3) (0, 4)
  (1, 1) (1, 2) (1, 3) (1, 4)
*/
public class Day11 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[][] arr = new int[6][6];
        for (int i = 0; i < 6; i++)
            arr[i] = Stream.of(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int result = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
                if (sum > result)
                    result = sum;
            }
        }

        System.out.println(result);
        scanner.close();
    }
}
