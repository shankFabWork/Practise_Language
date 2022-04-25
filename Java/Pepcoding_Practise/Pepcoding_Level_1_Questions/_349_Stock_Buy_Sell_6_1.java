// Buy And Sell Stocks - Two Transactions Allowed
import java.util.*; 

public class _349_Stock_Buy_Sell_6_1
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
		// k is number of transaction
		int k = scn.nextInt();
		Buy_And_Sell_Stocks_k_Transactions_Allowed(arr,n,k);
	}

	public static void Buy_And_Sell_Stocks_k_Transactions_Allowed(int arr[],int n,int k)
	{
		// r -> day
		// c -> transaction
		// num_tras -> number of transaction
		int dp[][] = new int[k+1][n];
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<n;j++)
			{
				int curr_pro = dp[i][j-1];
				for(int s=0;s<j;s++)
				{
					if(dp[i-1][s]+(arr[j]-arr[s]) > curr_pro)
					{
						curr_pro = dp[i-1][s]+(arr[j]-arr[s]);
					}
				}
				dp[i][j] = curr_pro;
			}
		}

		System.out.print(dp[k][n-1]);


		// for(int i=1;i<=k;i++)
		// {
		// 	for(int j=1;j<=n;j++)
		// 	{
		// 		System.out.print(dp[i][j]+" ");
		// 	}
		// 	System.out.println();
		// }
	}

}