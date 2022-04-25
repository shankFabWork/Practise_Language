import java.util.*; 

public class _46_Bar_chart
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			int a = scn.nextInt();
			arr[i] = a;
		}
		int max_elem = Integer.MIN_VALUE;
		for(int i=0;i<n;i++)
		{
			if(max_elem < arr[i])
			{
				max_elem = arr[i];
			}
		}
		for(int floor = max_elem;floor >= 1;floor--)
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i] >= floor)
				{
					System.out.print("*\t");
				}
				else
				{
					System.out.print("\t");
				}
			}
			System.out.println();
		}
	}
}