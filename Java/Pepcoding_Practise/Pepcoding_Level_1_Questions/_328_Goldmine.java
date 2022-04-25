import java.util.*; 

public class _328_Goldmine
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int m = scn.nextInt();
		int arr[][] = new int[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				arr[i][j] = scn.nextInt();
			}
		}
		golmine(arr);
	}
	public static void golmine(int arr[][])
	{
		int n = arr.length;
		int m = arr[0].length;
		int dp[][] = new int[n][m];
		// for(int i=0;i<n;i++)
		// {
		// 	dp[i][m-1] = arr[i][m-1];
		// }
		for(int j=m-1;j>=0;j--)
		{
			for(int i=n-1;i>=0;i--)
			{
				if(j == m-1)
				{
					dp[i][j] = arr[i][j];
				}
				else if(i == 0)
				{
					dp[i][j] = Math.max(dp[i][j+1],dp[i+1][j+1])+arr[i][j];
				}
				else if(i == n-1)
				{
					dp[i][j] = Math.max(dp[i][j+1],dp[i-1][j+1])+arr[i][j];
				}
				else 
				{
					dp[i][j] = Math.max(dp[i][j+1], Math.max(dp[i-1][j+1],dp[i+1][j+1]) )+arr[i][j];
				}
			}
		}
		int max = Integer.MIN_VALUE;
		for(int i=0;i<n;i++)
		{
			max = Math.max(dp[i][0],max);
		}
		System.out.print(max);
	}
}