import java.util.*;

public class _119_Stock_span_simple 
{
    public static void main(String[] args)
    {
        int arr[] = {2,5,9,3,1,12,6,8,7};
        int n = arr.length;
        int span[] = new int[n];
        Stack <Integer> s = new Stack<Integer>();
        s.push(0);
        span[0] = 1;
        // System.out.print(1+" ");
        for(int i=1;i<n;i++)
        {
            while(s.size() > 0 && arr[i] >= arr[s.peek()])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                span[i] = i+1;
                // System.out.print(i+1+" ");
            }
            else
            {
                span[i] = i-s.peek();
                // System.out.print(i-s.peek()+" ");
            }
            s.push(i);
        }
        // return span;
        for(int elem:span)
        {
            System.out.print(elem+" ");
        }
    }
}
