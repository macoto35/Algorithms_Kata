package blog.ds;

import java.util.StringJoiner;

public class StackFixedArray {
    int top = 0;

    int[] arr = new int[4];

    public String toString() {
        StringJoiner joiner = new StringJoiner(",");
        for(int i = 0; i < top; i++)
            joiner.add(Integer.toString(arr[i]));

        return joiner.toString();
    }

    public void push(int data) {
        if (this.top >= this.arr.length)
            throw new ArrayIndexOutOfBoundsException();

        this.arr[top++] = data;
    }

    public Integer pop() {
        if (this.empty())
            return null;
        return this.arr[--this.top];
    }

    public boolean empty() {
        return this.top == 0;
    }

    public Integer peek() {
        if (this.empty())
            return null;
        return this.arr[this.top - 1];
    }

    public int search(int data) {
        for (int i = 0; i < this.top; i++) {
            if (data == this.arr[i])
                return i;
        }
        return -1;
    }
}
