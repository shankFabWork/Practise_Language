// Buy And Sell Stocks - Two Transactions Allowed
import java.util.*; 

public class _348_Stock_Buy_Sell_5
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

		int max_profit1 = 0;
		int dp1[] = new int[n];
		// lsf - least so far
		int lsf = arr[0];
		dp1[0] = 0;
		for(int i=1;i<n;i++)
		{
			if(arr[i] < lsf)
			{
				lsf = arr[i];
			}
			max_profit1 = arr[i]-lsf;
			if(dp1[i-1] < max_profit1)
			{
				dp1[i] = max_profit1;
			}
			else
			{
				dp1[i] = dp1[i-1];
			}
		}

		int max_profit2 = 0;
		int dp2[] = new int[n];
		// msf - max so far
		int msf = arr[n-1];
		dp2[n-1] = 0;
		for(int i=n-2;i>=0;i--)
		{
			if(arr[i] > msf)
			{
				msf = arr[i];
			}
			max_profit2 = msf-arr[i];
			if(dp2[i+1] < max_profit2)
			{
				dp2[i] = max_profit2;
			}
			else
			{
				dp2[i] = dp2[i+1];
			}
		}

		int final_max_profit = 0;
		for(int i=0;i<n;i++)
		{
			if(dp1[i]+dp2[i] > final_max_profit)
			{
				final_max_profit = dp1[i]+dp2[i];
			}
		}
		System.out.print(final_max_profit);



	}
}