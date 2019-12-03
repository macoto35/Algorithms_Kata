package blog.ds;



public class BitManipulation {
    public int setUnion(int a, int b) {
        return a | b;
    }

    public int setIntersection(int a, int b) {
        return a & b;
    }

    public int setSubtraction(int a, int b) { return a & ~b; }

    public int setNegationAllBitsWithNot(int a) { return ~a; }

    public int setNegationAllBitsWithXor(int a) { return a ^ 0xffffffff; } // f = 1111 so 0xffffffff is 32bits all 1 integer (1111 1111 1111 1111 1111 1111 1111 1111)

    public int setBit(int a, int shift) { return a |= 1 << shift; }

    public int clearBit(int a, int shift) { return a &= ~(1 << shift); }

    public boolean testBit(int a, int shift) { return (a & 1 << shift) != 0; }

    public int extractLastBit(int a) {
        //return a & ~(a-1);
        return a ^ (a & (a-1));
    }

    public int removeLastBit(int a) { return a & (a-1); }

    public int getAllOneBits() {
        return ~0;
    }

    public void basic() {
        System.out.println("---> Set union: A | B");
        System.out.println("2 | 5 = " + setUnion(2, 5));
        System.out.println("1 | 5 = " + setUnion(1, 5));

        System.out.println("---> Set intersection: A & B");
        System.out.println("2 & 5 = " + setIntersection(2, 5));
        System.out.println("1 & 5 = " + setIntersection(1, 5));

        System.out.println("---> Set subtraction: A & ~B");
        System.out.println("2 & 5 = " + setSubtraction(2, 5));
        System.out.println("1 & 5 = " + setSubtraction(1, 5));

        System.out.println("---> Set negation ALL_BITS: ^A or ~A");
        System.out.println("~2 = " + setNegationAllBitsWithNot(2));
        System.out.println("~5 = " + setNegationAllBitsWithNot(5));
        System.out.println("^2 = " + setNegationAllBitsWithXor(2));
        System.out.println("^5 = " + setNegationAllBitsWithXor(5));

        System.out.println("---> Set bit: A |= 1 << bit");
        System.out.println("2, set third bit = " + setBit(2, 2));
        System.out.println("5, set second bit = " + setBit(5, 1));

        System.out.println("---> clear bit: A &= ~(1 << bit)");
        System.out.println("5, clear first bit = " + clearBit(5, 0));
        System.out.println("7, clear second bit = " + clearBit(7, 1));

        System.out.println("---> test bit: A & 1 << shift != 0 ");
        System.out.println("5, test first bit = " + testBit(5, 0));
        System.out.println("5, test second bit = " + testBit(5, 1));
        System.out.println("5, test third bit = " + testBit(5, 2));

        System.out.println("---> Extract last bit: A&~(A-1) or A^(A&(A-1)) ");
        System.out.println("2, extract last bit = " + extractLastBit(2));
        System.out.println("5, extract last bit = " + extractLastBit(5));

        System.out.println("---> Remove last bit: A&(A-1) ");
        System.out.println("2, remove last bit = " + removeLastBit(2));
        System.out.println("5, remove last bit = " + removeLastBit(5));

        System.out.println("---> get all 1-bits: ~0 ");
        System.out.println("get all 1-bits = " + Integer.toBinaryString(getAllOneBits()));
    }

    public void countNumberOfOne(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        System.out.println("count number of one: " + count);
    }

    public int xorTrickGetSum(int a, int b) {
        return b == 0? a: xorTrickGetSum(a ^ b, (a & b) << 1);
    }

    public int xorTrickMissingNumber(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            result ^= i;
            result ^= nums[i];
        }

        return result ^ nums[nums.length - 1];
    }

    public long orTrickLargestPower(long n) {
        n = n | (n >> 1);
        n = n | (n >> 2);
        n = n | (n >> 4);
        n = n | (n >> 8);
        n = n | (n >> 16);
        return (n + 1) >> 1;
    }

    public int reverseBits(int n) {
        return n ^ ~0;
    }

    public static void main(String[] args) {
        BitManipulation bm = new BitManipulation();

        // bm.basic();
        // bm.countNumberOfOne(5);
        // System.out.println("7 + 1 = " + bm.xorTrickGetSum(7, 1));
        // System.out.println("[0, 1, 2, 3, 4, 5, 7], missing number is " + bm.xorTrickMissingNumber(new int[]{0, 1, 2, 3, 4, 5, 7}));
        // System.out.println("[0, 1, 2, 4], missing number is " + bm.xorTrickMissingNumber(new int[]{0, 1, 2, 4}));
        // System.out.println("Largest power? " + Long.toBinaryString(bm.orTrickLargestPower(10)));
        System.out.println(Integer.toBinaryString(124) + ", reverse bit? " + Integer.toBinaryString(bm.reverseBits(124)));
    }
}


