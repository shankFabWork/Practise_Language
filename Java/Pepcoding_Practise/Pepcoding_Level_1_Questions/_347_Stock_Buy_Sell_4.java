// Buy And Sell Stocks With Cooldown - Infinite Transaction Allowed
import java.util.*; 

public class _347_Stock_Buy_Sell_4
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

		// old bought state profit
		int obsp = -1*arr[0];
		// old sold state profit
		int ossp = 0;
		// old cool-down state profit
		int ocsp = 0;
		for(int i=1;i<n;i++)
		{
			int nbsp = 0;
			int nssp = 0;
			int ncsp = 0;
			
			// bsp
			if(ocsp-arr[i] > obsp)
			{
				nbsp = ocsp-arr[i];
			}
			else
			{
				nbsp = obsp;
			}
			
			// ssp
			if(arr[i]+obsp > ossp)
			{
				nssp = arr[i]+obsp;
			}
			else
			{
				nssp = ossp;
			}

			// csp
			if(ossp > ocsp)
			{
				ncsp = ossp;
			}
			else
			{
				ncsp = ocsp;
			}
			obsp = nbsp;
			ossp = nssp;
			ocsp = ncsp;
		}
		System.out.print(ossp);
	}
}