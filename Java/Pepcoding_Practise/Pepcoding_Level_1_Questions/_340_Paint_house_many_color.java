import java.util.*;

// Paint Hourse many color
public class _340_Paint_house_many_color 
{
    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        int r = scn.nextInt();
        int c = scn.nextInt();
        int arr[][] = new int[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                arr[i][j] = scn.nextInt();
            }
        }
        // Paint_house_many_color_1(arr);
        // TC- O(r*c^2)
        Paint_house_many_color_2(arr);
        // TC - O(r*c)
    }    

    public static void Paint_house_many_color_2(int arr[][])
    {
        int min = Integer.MAX_VALUE;
        int smin = Integer.MAX_VALUE;
        int r = arr.length;
        int c = arr[0].length;
        int dp[][] = new int[r][c];
        for(int j=0;j<c;j++)
        {
            dp[0][j] = arr[0][j];
            if(arr[0][j] <= min)
            {
                smin = min;
                min = arr[0][j];
            }
            else if(arr[0][j] <= smin)
            {
                smin = arr[0][j];
            }
        }
        int nmin = 0;
        int nsmin = 0;
        for(int i=1;i<r;i++)
        {
            nmin = Integer.MAX_VALUE;
            nsmin = Integer.MAX_VALUE;
            for(int j=0;j<c;j++)
            {
                if(dp[i-1][j] == min)
                {
                    dp[i][j] = smin + arr[i][j];
                }
                else
                {
                    dp[i][j] = min + arr[i][j];
                }
                if(dp[i][j] <= nmin)
                {
                    nsmin = nmin;
                    nmin = dp[i][j];
                }
                else if(dp[i][j] <= nsmin)
                {
                    nsmin = dp[i][j];
                }
            }
            min = nmin;
            smin = nsmin;
            // System.out.println(min+"-"+smin);
        }
        System.out.print(min);
    }

    public static void Paint_house_many_color_1(int arr[][])
    {
        // houses
        int r = arr.length;
        // color
        int c = arr[0].length; 

        int dp[][] = new int[r][c];
        for(int i=0;i<c;i++)
        {
            dp[0][i] = arr[0][i];
        }
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                dp[i][j] = arr[i][j];
                int min_val = Integer.MAX_VALUE;
                for(int k=0;k<c;k++)
                {
                    if(k != j)
                    {
                        min_val = Math.min(min_val,dp[i-1][k]);
                    }
                }
                dp[i][j] += min_val;
            }
        }
        int min_elem = dp[r-1][0];
        for(int i=1;i<c;i++)
        {
            if(min_elem > dp[r-1][i])
            {
                min_elem = dp[r-1][i];
            }
        }
        System.out.print(min_elem);
    }
}

