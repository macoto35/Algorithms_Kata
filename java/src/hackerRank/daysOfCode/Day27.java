package hackerRank.daysOfCode;

import java.util.*;
import java.util.stream.*;

/*
- Unit Testing: verify that individual units of code. Functions work as expected.
                1. Testing all outcomes depends on the arguments
                2. Edge case
                3. Exception
e.g.
*/
public class Day27 {

    public int minimumIndex(int[] seq) throws IllegalArgumentException {
        if (seq == null || seq.length == 0)
            throw new IllegalArgumentException("Cannot get the minimum value index from an empty sequence.");

        int minIdx = 0;
        for (int i = 0; i < seq.length; i++) {
            if (seq[i] < seq[minIdx])
                minIdx = i;
        }

        return minIdx;
    }

    public class TestDataEmptyArray {
        public int[] getArray() {
            return null;
        }
    }

    public class TestDataUniqueValues {
        private int minIdx;

        public int[] getArray() {
            Set<Integer> set = new HashSet<>();

            Random r = new Random();
            while(set.size() < 5)
                set.add(r.nextInt(50) + 1);

            int i = 0, minVal = 51;
            int[] arr = new int[set.size()];
            for (Integer val : set) {
                arr[i] = val;

                if (arr[i] < minVal) {
                    minVal = arr[i];
                    minIdx = i;
                }

                i++;
            }

            return arr;
        }

        public int getExpectedResult() {
            return this.minIdx;
        }
    }

    public class TestDataExactlyTwoDifferentMinimums {
        private int minIdx;

        public int[] getArray() {
            Set<Integer> set = new HashSet<>();

            Random r = new Random();
            while (set.size() < 5)
                set.add(r.nextInt(50) + 1);

            int[] arr = new int[set.size() + 1];
            int i = 0, minVal = 51;
            for (Integer val : set) {
                arr[i] = val;

                if (arr[i] < minVal) {
                    minVal = arr[i];
                    minIdx = i;
                }

                i++;
            }

            arr[set.size()] = minVal;
            return arr;
        }

        public int getExpectedResult() {
            return minIdx;
        }
    }

    public void printArray(String desc, int[] arr) {
        System.out.print(desc + ": ");
        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
    }

    public void testWithEmptyArray() {
        try {
            TestDataEmptyArray obj = new TestDataEmptyArray();
            this.minimumIndex(obj.getArray());
        } catch (IllegalArgumentException ex) {
            return;
        }

        throw new AssertionError("Exception wasn't thrown as expected.");
    }

    public void testWithUniqueValues() {
        TestDataUniqueValues obj = new TestDataUniqueValues();
        int[] seq = obj.getArray();
        this.printArray("testWithUniqueValues", seq);

        if (seq.length < 2)
            throw new AssertionError("less than 2 elements in the array.");

        if (IntStream.of(seq).distinct().toArray().length != seq.length)
            throw new AssertionError("not all values are unique.");

        if (this.minimumIndex(seq) != obj.getExpectedResult())
            throw new AssertionError("result is different than the expected result.");
    }

    public void testWithExactlyTwoDifferentMinimums() {
        TestDataExactlyTwoDifferentMinimums obj = new TestDataExactlyTwoDifferentMinimums();
        int[] seq = obj.getArray();
        this.printArray("testWithExactlyTwoDifferentMinimums", seq);

        if (seq.length < 2)
            throw new AssertionError("less than 2 elements in the array.");

        int[] tmp = seq.clone();
        Arrays.sort(tmp);
        if ( !(tmp[0] == tmp[1] && (tmp.length == 2 || tmp[1] < tmp[2])) )
            throw new AssertionError("there are not exactly two minimums in the array.");

        if (this.minimumIndex(seq) != obj.getExpectedResult())
            throw new AssertionError("result is different than the expected result");
    }

    public void run() {
        this.testWithEmptyArray();
        this.testWithUniqueValues();
        this.testWithExactlyTwoDifferentMinimums();
    }

    public static void main(String[] args) {
        Day27 day27 = new Day27();
        day27.run();
    }
}
