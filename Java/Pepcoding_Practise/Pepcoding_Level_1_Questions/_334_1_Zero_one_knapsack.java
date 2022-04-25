import java.util.*; 

public class _334_1_Zero_one_knapsack
{
	public static void main(String []args)
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
		int target = scn.nextInt();
		Zero_one_knapsack(wt,val,target);
	}

	public static void Zero_one_knapsack(int wt[],int val[],int target)
	{
		int n = wt.length;
		// by default vlaue in array or matrix is 0
		int dp[][] = new int[n+1][target+1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=target;j++)
			{
				// if(i == 0)
				// {
				// 	dp[i][j] = 0;
				// }
				// else if(j == 0)
				// {
				// 	dp[i][j] = 0;
				// }
				if(wt[i-1] > j)
				{
					dp[i][j] = dp[i-1][j];
				}
				else if(wt[i-1] <= j)
				{
					int each_val = dp[i-1][j];
					if(each_val <= dp[i-1][j-wt[i-1]]+val[i-1])
					{
						dp[i][j] = val[i-1] + dp[i-1][j-wt[i-1]];
					}
					else
					{
						dp[i][j] = dp[i-1][j];
					}
				}
			}
		}
		System.out.print(dp[n][target]);
	}
}