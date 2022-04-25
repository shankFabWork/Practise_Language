import java.util.Scanner;

public class _15_1_The_curious_case_of_benjamin_bulbs {
    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        int n =scn.nextInt();
        int arr[] = new int[n];
        int max = Integer.MIN_VALUE;
        int second_max = 0;
        int min = Integer.MAX_VALUE;
        int second_min = 0;
        for(int i=0;i<n;i++)
        {
            int val = scn.nextInt();
            arr[i] = val;
        }
        for(int i=0;i<n;i++)
        {
            if(max < arr[i])
            {
                second_max = max;
                max = arr[i];
            }
            else if(second_max < max && second_max < arr[i])
            {
                second_max = arr[i];
            }
            if(min > arr[i])
            {
                second_min = min;
                min = arr[i];
            }
            else if(second_min > min && second_min > arr[i])
            {
                second_min = arr[i];
            }
        }
        System.out.println(second_max+" "+second_min);
    }
}
