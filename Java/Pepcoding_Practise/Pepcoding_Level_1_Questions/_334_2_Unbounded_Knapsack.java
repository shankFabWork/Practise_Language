import java.util.*;

public class _334_2_Unbounded_Knapsack
{
    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int wt[] = new int[n];
        int val[] = new int[n];
        for(int i=0;i<n;i++)
        {
            val[i] = scn.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            wt[i] = scn.nextInt();
        }
        int cap = scn.nextInt();
        Unbounded_Knapsack(wt,val,cap);
    }

    public static void Unbounded_Knapsack(int wt[],int val[],int cap)
    {
        int n = wt.length;
        int dp[] = new int[cap+1];
        for(int bagc=1;bagc<=cap;bagc++)
        {
            int max_val = 0;
            for(int i=0;i<n;i++)
            {
                if(wt[i]<=bagc)
                {
                    if(max_val < dp[bagc-wt[i]]+val[i])
                    {
                        max_val = dp[bagc-wt[i]]+val[i];
                    }
                }   
            }
            dp[bagc] = max_val;
        }
        System.out.print(dp[cap]);
    }
}