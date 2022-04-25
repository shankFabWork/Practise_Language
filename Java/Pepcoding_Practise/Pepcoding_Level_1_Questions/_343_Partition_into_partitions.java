import java.util.*; 

public class _343_Partition_into_partitions
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		// no of elements [member]
		int n = scn.nextInt();
		// no of subset [team can be partition]
		int k = scn.nextInt();

		if(n == 0 || k == 0 || n < k)
		{
			System.out.print(0);
			return;
		}

		long dp[][] = new long[k+1][n+1];

		for(int t=1;t<=k;t++)
		{
			for(int p=1;p<=n;p++)
			{
				if(t > p)
				{
					dp[t][p] = 0;
				}
				else if(t == p)
				{
					dp[t][p] = 1;
				}
				else
				{
					dp[t][p] = dp[t][p-1]*t+dp[t-1][p-1];
				}
			}
		}
		
		System.out.print(dp[k][n]);
		// for(int t=1;t<=k;t++)
		// {
		// 	for(int p=1;p<=n;p++)
		// 	{
		// 		System.out.print(dp[t][p]+" ");
		// 	}
		// 	System.out.println();
		// }

	}
}