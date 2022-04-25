import java.util.*;

public class _118_Next_greater_element_element_to_the_right_alternative_sol 
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scn.nextInt();
        }
        Stack <Integer> st = new Stack <Integer>();
        int nge[] = new int[n];
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(st.size() > 0 &&  arr[i] > arr[st.peek()])
            {
                int pos = st.peek();
                nge[pos] = arr[i];
                st.pop();
            }    
            st.push(i);
        }
        while(st.empty() != true)
        {
            int pos = st.peek();
            nge[pos] = -1;
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            System.out.println(nge[i]+" ");
        }
    }
}
