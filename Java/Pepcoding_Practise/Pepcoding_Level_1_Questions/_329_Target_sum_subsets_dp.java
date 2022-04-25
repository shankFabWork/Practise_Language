import java.util.*; 

public class _329_Target_sum_subsets_dp
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
		int target = scn.nextInt();
		boolean dp[][] = new boolean[n+1][target+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=target;j++)
			{
				if(i == 0 && j == 0)
				{
					dp[i][j] = true;
				}
				else if(i == 0)
				{
					dp[i][j] = false;
				}
				else if(j == 0)
				{
					dp[i][j] = true;
				}
				else if(dp[i-1][j] == true)
				{
					dp[i][j] = true;
				}
				else
				{
					int val = arr[i-1];
					if(val <= j)
					{
						dp[i][j] = dp[i-1][j-val];
					}
				}
			}
		}
		System.out.print(dp[n][target]);
	}
}

