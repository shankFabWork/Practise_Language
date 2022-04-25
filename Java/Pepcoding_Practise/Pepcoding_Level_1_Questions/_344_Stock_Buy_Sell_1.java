import java.util.*; 

public class _344_Stock_Buy_Sell_1
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
		int lsf = Integer.MAX_VALUE;
		int ans = Integer.MIN_VALUE;
		for(int i=0;i<n;i++)
		{
			if(arr[i] < lsf)
			{
				lsf = arr[i];
			}
			int temp = arr[i] - lsf;
			if(temp > ans)
			{
				ans = temp;
			}
		}
		System.out.print(ans);
	}
}