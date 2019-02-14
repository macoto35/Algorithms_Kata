package blog.ds;

import java.util.StringJoiner;
import java.lang.ArrayIndexOutOfBoundsException;

public class QueueArray {

    private final int size = 5;

    private int[] arr = new int[this.size];

    private int read = -1;

    private int write = -1;



    public String toString() {
        if (this.empty())
            return null;

        StringJoiner joiner = new StringJoiner(",");
        int i;
        for (i = this.read; i != this.write; i = (i + 1) % this.size)
            joiner.add(Integer.toString(this.arr[i]));
        joiner.add(Integer.toString(this.arr[i]));

        return joiner.toString();
    }

    public boolean empty() {
        return this.read == -1;
    }

    public boolean full() {
        return (this.write + 1) % this.size == this.read;
    }

    public void enqueue(int data) {
        if (this.full())
            throw new ArrayIndexOutOfBoundsException();

        if (this.read == -1)
            this.read = 0;

        this.write = (this.write + 1) % this.size;
        this.arr[this.write] = data;
    }

    public Integer dequeue() {
        if (this.empty())
            return null;

        int result = this.arr[this.read];

        if (this.read == this.write)
            this.read = this.write = -1;
        else
            this.read = (this.read + 1) % this.size;

        return result;
    }
}
