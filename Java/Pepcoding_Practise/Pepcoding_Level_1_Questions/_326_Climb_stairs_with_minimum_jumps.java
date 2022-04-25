import java.util.*; 

public class _326_Climb_stairs_with_minimum_jumps
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
		Climb_stairs_with_minimum_jumps(arr);
	}

	public static void Climb_stairs_with_minimum_jumps(int arr[])
	{
		int n =arr.length;
		Integer dp[] = new Integer[n+1];
		dp[n] = 0;
		for(int i=n-1;i>=0;i--)
		{
			int min = Integer.MAX_VALUE;
			for(int j=1;j<=arr[i] && i+j < dp.length;j++)
			{
				if(dp[i+j] != null)
				{
					min = Math.min(min,dp[i+j]);
				}
			}
			if(min == Integer.MAX_VALUE)
			{
				dp[i] = null;
			}
			else
			{
				dp[i] = min+1;
			}
		}
		// if dp[0] is null that means their no path to reach the end
		System.out.println(dp[0]);
	}

}