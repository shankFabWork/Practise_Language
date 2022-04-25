import java.util.*;

public class _8_Arraylists_Stacks_and_Queues_in_JAVA_Java_Tutorials_for_C_Coders
{
    public static void main(String args[])
    {
        System.out.println("ArrayList --------------------");
        ArrayList <Integer> al = new ArrayList<Integer>();
        System.out.println(al+" "+al.size());
        al.add(10);
        al.add(20);
        al.add(30);
        System.out.println(al+" "+al.size());
        int val = al.get(1);
        System.out.println(val);
        al.set(1,100);
        System.out.println(al+" "+al.size());
        al.add(1,120);
        System.out.println(al+" "+al.size());
        al.remove(1);
        System.out.println(al+" "+al.size());
        System.out.println("------------------");
        for(int data:al)
        {
            System.out.print(data+" ");
        }
        System.out.println();
        System.out.println("------------------");
        for(int i=0;i<al.size();i++)
        {
            int a = al.get(i);
            System.out.print(a+" ");
        }
        System.out.println("Stack --------------------");
        Stack <Integer> s = new Stack <Integer>();
        s.push(10);
        s.push(20);
        System.out.println(s);
        s.push(30);
        System.out.println(s);
        System.out.println(s.peek());
        System.out.println(s);
        s.pop();
        System.out.println(s);
        System.out.println("Queue --------------------");
        ArrayDeque <Integer> que = new ArrayDeque<Integer>();
        que.addLast(10);
        que.addLast(20);
        que.addLast(30);
        System.out.println(que);
        que.addFirst(90);
        System.out.println(que);
        System.out.println(que.size());
        que.addLast(40);
        System.out.println(que);
        System.out.println(que.getFirst());
        System.out.println(que);
        System.out.println(que.removeFirst());
        System.out.println(que);
        // Size Capacity DataPointer
    }
}