import java.util.*; 

public class _333_Coin_change_permutation
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int coins[] = new int[n];
		for(int i=0;i<n;i++)
		{
			coins[i] = scn.nextInt();
		}
		int target = scn.nextInt();
		Coin_change_combination(coins,target);
	}
	public static void Coin_change_combination(int coins[],int target)
	{
		int dp[] = new int[target+1];
		dp[0] = 1;
		for(int i=0;i<=target;i++)
		{
			for(int j=0;j<coins.length;j++)
			{
				if(coins[j] <= i)
				{
					dp[i] += dp[i-coins[j]];
				}
			}
		}
		System.out.print(dp[target]);
	}
}