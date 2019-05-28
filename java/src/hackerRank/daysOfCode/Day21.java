package hackerRank.daysOfCode;

public class Day21<T> {

    public void printArray(T[] arr) {
        for (T t : arr)
            System.out.println(t);
    }

    public static void main(String[] args) {
        Integer[] intArr = {1,2,3};
        Day21<Integer> day21Int = new Day21<>();
        day21Int.printArray(intArr);

        String[] strArr = {"one", "two", "three"};
        Day21<String> day21Str = new Day21<>();
        day21Str.printArray(strArr);
    }
}
