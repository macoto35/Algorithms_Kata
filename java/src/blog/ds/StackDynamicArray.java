package blog.ds;

import java.util.Arrays;
import java.util.stream.Collectors;

public class StackDynamicArray {
    private int top = 0;

    private int[] arr = new int[]{0};

    public String toString() {
        return Arrays.stream(arr).mapToObj(String::valueOf).collect(Collectors.joining(","));
    }

    public void push(int data) {
        if (this.top >= this.arr.length) {
            int length = this.arr.length;
            int[] newArr = new int[length * 2];

            for(int i = 0; i < length; i++)
                newArr[i] = this.arr[i];

            this.arr = newArr;
        }
        this.arr[this.top++] = data;
    }

    public Integer pop() {
        if (this.empty()) {
            return null;
        } else if (this.top < this.arr.length / 2) {
            int length = this.arr.length;
            int[] newArr = new int[length / 2];

            for(int i = 0; i < this.top; i++)
                newArr[i] = this.arr[i];

            int result = this.arr[--this.top];
            this.arr = newArr;

            return result;
        } else {
            return this.arr[--this.top];
        }
    }

    public boolean empty() {
        return this.top == 0;
    }

    public Integer peek() {
        if (empty())
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

