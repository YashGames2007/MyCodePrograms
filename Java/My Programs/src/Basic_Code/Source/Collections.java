package Basic_Code.Source;

import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Stack;


public class Collections {
    public static void main(String[] args) {
        System.out.printf("\nHello World!");

        ArrayList<Integer> list = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        HashSet<Integer> set = new HashSet<>();

        list.add(1);
        stack.add(2);
        queue.add(3);
        set.add(4);

        set.addAll(list);
        queue.addAll(set);
        stack.addAll(queue);
        list.addAll(stack);

        System.out.printf("\n");
        System.out.print(set);
        System.out.printf("\n");
        System.out.print(queue);
        System.out.printf("\n");
        System.out.print(stack);
        System.out.printf("\n");
        System.out.print(list);
    }
}
