import java.util.*; 

public class _332_Coin_change_combination
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
		Coin_change_combination(arr,target);
	}

	public static void Coin_change_combination(int arr[],int target)
	{
		int n = arr.length;
		int dp[] = new int[target+1];
		dp[0] = 1;
		for(int i=0;i<n;i++)
		{
			for(int j=arr[i];j<=target;j++)
			{
				dp[j] += dp[j-arr[i]];
			}
		}
		System.out.print(dp[target]);
	}

}