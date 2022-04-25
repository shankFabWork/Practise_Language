import java.util.*;

public class _3_sum_1 {
    public static void main(String args[])
    {
        // int arr[] = {-2,-2,-2,-1,-1,0,0,0,2,2,2};
        // int arr[] = {-1,0,1,2,-1,-4};
        int arr[] = {-2,0,0,2,2};
        Arrays.sort(arr);
        int n = arr.length;
        List<List<Integer>> lst = new ArrayList<>();
        if(n < 3)
        {
            System.out.print(lst);
            return;
        }
        for(int i=0;i<n-2;i++)
        {
            int n1 = arr[i];
            int l = i+1;
            int h = n-1;
            if(i != 0 && arr[i] == arr[i-1])
            {
                continue;
            }
            while(l < h)
            {
                if(arr[l]+arr[h] == -1*n1)
                {
                    List<Integer> l1 = new ArrayList<>();
                    l1.add(n1);
                    l1.add(arr[l]);
                    l1.add(arr[h]);
                    lst.add(l1);
                    while(l<h && (arr[l] == arr[l+1]))
                    {
                        l++;
                    }
                    while(l<h && arr[h] == arr[h-1])
                    {
                        h--;
                    }
                    l++;
                    h--;
                }
                else if(arr[l]+arr[h] > -1*n1)
                {
                    h--;
                }
                else if(arr[l]+arr[h] < -1*n1)
                {
                    l++;
                }
            }
        }
        System.out.print(lst);


    }
}
