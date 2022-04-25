import java.util.*;

public class a {
    public static void main(String []args)
    {
        int arr[] =  {5,3,8,-2,7};
        int n = arr.length;

        Stack <Integer> s = new Stack <Integer>();
        s.push(0);
        int nge[] = new int[n];
        for(int i=1;i<n;i++)
        {
            while(s.size() > 0 && arr[i] >= arr[s.peek()])
            {
                int elem = s.peek();
                nge[elem] = arr[i];
                s.pop();    
            }
            s.push(i);
        }
        while(s.size() > 0)
        {
            int elem = s.peek();
            nge[elem] = -1;
            s.pop();
        }
        for(int elem:nge)
        {
            System.out.print(elem+" ");
        }
    }
}
