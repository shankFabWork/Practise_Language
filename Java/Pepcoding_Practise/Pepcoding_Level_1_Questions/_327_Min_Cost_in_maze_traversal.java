import java.util.*; 

public class _327_Min_Cost_in_maze_traversal
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
		Min_Cost_in_maze_traversal(arr);
	}
	public static void Min_Cost_in_maze_traversal(int arr[][])
	{
		int dp[][] = new int[arr.length][arr[0].length];
		for(int i=arr.length-1;i>=0;i--)
		{
			for(int j=arr[0].length-1;j>=0;j--)
			{
				if(i == arr.length-1 && j == arr[0].length-1)
				{
					dp[i][j] = arr[i][j];
				}
				else if(i == arr.length-1)
				{
					dp[i][j] = dp[i][j+1]+arr[i][j];
				}
				else if(j == arr[0].length-1)
				{ 
					dp[i][j] = dp[i+1][j]+arr[i][j];
				}
				else
				{
					dp[i][j] = Math.min(dp[i+1][j],dp[i][j+1])+arr[i][j];
				}
			}
		}
		System.out.print(dp[0][0]);
	}
}