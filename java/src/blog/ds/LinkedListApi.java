package blog.ds;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class LinkedListApi {

    private LinkedList<Integer> getLinkedList() {
        // {4, 8, 9, 2, 1, 3, 5, 6, 7}
        LinkedList<Integer> list = new LinkedList<Integer>();
        list.add(1);
        list.add(0, 2);
        list.addLast(3);
        list.addFirst(4);
        list.addAll(new ArrayList<Integer>(){{add(5); add(6); add(7);}});
        list.addAll(1, new ArrayList<Integer>(){{ add(8); add(9); }});

        return list;
    }

    public Integer[] add() {
        return this.getLinkedList().toArray(new Integer[]{});
    }

    public Integer[] remove() {
        LinkedList<Integer> list = new LinkedList<>();
        // {1,7,7,2,3,7,7,4,5,6,7,2,3,7}
        list.addAll(new ArrayList<Integer>(){{ add(1); add(7); add(7); add(2); add(3); add(7); add(7); add(4); add(5); add(6); add(7); add(2); add(3); add(7); }});

        list.remove();
        list.remove(2);
        list.remove((Integer) 7);
        list.removeFirst();
        list.removeLast();
        list.removeFirstOccurrence((Integer) 7);
        list.removeLastOccurrence((Integer) 7);

        return list.toArray(new Integer[]{});
    }

    public Integer[] removeAll() {
        LinkedList<Integer> list = this.getLinkedList();
        list.clear();

        return list.toArray(new Integer[]{});
    }

    public Integer[] get() {
        // {4, 8, 9, 2, 1, 3, 5, 6, 7, 5}
        LinkedList<Integer> list = this.getLinkedList();
        list.add(5);
        Integer[] result = new Integer[6];

        if (list.contains((Integer) 9))
            result[0] = list.size();

        result[1] = list.get(5);
        result[2] = list.getFirst();
        result[3] = list.getLast();
        result[4] = list.indexOf((Integer) 5);
        result[5] = list.lastIndexOf((Integer) 5);

        return result;
    }

    public Integer etc() {
        LinkedList<Integer> list = new LinkedList<Integer>();

        // {2, 1, 3}
        list.offer(1);
        list.offerFirst(2);
        list.offerLast(3);

        // {8, 1, 3}
        list.set(0, 8);

        return list.element();
    }

    public Integer[] queue() {
        // {4, 8, 9, 2, 1, 3, 5, 6, 7}
        LinkedList<Integer> list = this.getLinkedList();
        Integer[] result = new Integer[6];

        // {4, 8, 7, 9, 9, 6}
        result[0] = list.poll();
        result[1] = list.pollFirst();
        result[2] = list.pollLast();
        result[3] = list.peek();
        result[4] = list.peekFirst();
        result[5] = list.peekLast();

        return result;
    }

    public Integer[] stack() {
        LinkedList<Integer> list = new LinkedList<Integer>();

        // {1, 2, 3, 4, 5}
        for (int i = 1; i < 6; i++)
            list.push(i);

        Integer[] result = new Integer[5];
        for (int j = 0; j < 5; j++)
            result[j] = list.pop();

        return result;
    }

    public Integer[] descIterator() {
        LinkedList<Integer> list = this.getLinkedList();
        List<Integer> result = new ArrayList<>();

        Iterator<Integer> it = list.descendingIterator();
        while(it.hasNext()) {
            result.add(it.next());
        }

        return result.toArray(new Integer[]{});
    }
}
