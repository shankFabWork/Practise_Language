import java.util.*; 

public class _44_Span_of_array
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
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		for(int i=0;i<n;i++)
		{
			if(max < arr[i])
			{
				max = arr[i];
			}
			if(min > arr[i])
			{
				min = arr[i];
			}
		}
		int span = max - min;
		System.out.print(span);
	}
}