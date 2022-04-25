import java.util.*;

public class a
{
    public static void main(String args[])
    {
        // Integer arr[] = { 13, 7, 6, 45, 21, 9, 101, 102 };
        // int n = arr.length;
        // int k = 
        Scanner scn = new Scanner(System.in);
        Integer n = scn.nextInt();
        Integer k = scn.nextInt();
        Integer arr[] = new Integer[n];
        
        for(int i=0;i<n;i++)
        {
            arr[i] = scn.nextInt();
        }
        Arrays.sort(arr, Collections.reverseOrder());
        int sum = 0;       
        int counter = 0;
        for(Integer elem:arr)
        {
            if(k > sum)
            {
                counter++;
            }
            else
            {
                break;
            }
            sum += elem;
        }
        if(counter == n)
        {
            System.out.print(-1);
        }
        else
        {
            System.out.print(counter);
        }
    }
}