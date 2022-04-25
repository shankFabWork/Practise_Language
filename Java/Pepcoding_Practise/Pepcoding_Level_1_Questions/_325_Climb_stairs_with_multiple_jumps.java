import java.util.*; 

public class _325_Climb_stairs_with_multiple_jumps
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
		Climb_stairs_with_multiple_jumps(arr);
	}

	public static void Climb_stairs_with_multiple_jumps(int arr[])
	{
		int n = arr.length;
		int dp[] = new int[n+1];
		dp[n] = 1;
		for(int i=n-1;i>=0;i--)
		{
			for(int j=1;j<=arr[i] && i+j < dp.length;j++)
			{
				dp[i] += dp[i+j];
			}
		} 
		System.out.print(dp[0]);
	}
}