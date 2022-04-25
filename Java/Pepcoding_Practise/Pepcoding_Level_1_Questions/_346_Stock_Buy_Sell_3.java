// Buy And Sell Stocks - Infinite Transactions Allowed

import java.util.*; 

public class _346_Stock_Buy_Sell_3
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
		// bought day
		int bd = 0;
		// sold day
		int sd = 0;
		int profit = 0;
		for(int i=1;i<n;i++)
		{
			if(arr[i] > arr[i-1])
			{
				sd++;
			}
			else
			{
				profit += arr[sd] - arr[bd];
				sd = bd = i;
			}
		}
		profit += arr[sd] - arr[bd];
		System.out.print(profit);
	}
}