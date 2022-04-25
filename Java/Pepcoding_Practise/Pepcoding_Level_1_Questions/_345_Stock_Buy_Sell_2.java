// Buy And Sell Stocks With Transaction Fee - Infinite Transactions Allowed
import java.util.*; 

public class _345_Stock_Buy_Sell_2
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
		int trans_fee = scn.nextInt();

		// old bought state profit
		int obsp = -1*arr[0];
		// old sold state profit
		int ossp = 0;

		for(int i=1;i<n;i++)
		{
			int nbsp = 0;
			int nssp = 0;
			if(ossp-arr[i] > obsp)
			{
				nbsp = ossp-arr[i];
			}
			else
			{
				nbsp = obsp;
			}
			if(arr[i]+obsp-trans_fee > ossp)
			{
				nssp = arr[i]+obsp-trans_fee;
			}
			else
			{
				nssp = ossp;
			}
			obsp = nbsp;
			ossp = nssp;
		}


		System.out.print(ossp);
	}

}