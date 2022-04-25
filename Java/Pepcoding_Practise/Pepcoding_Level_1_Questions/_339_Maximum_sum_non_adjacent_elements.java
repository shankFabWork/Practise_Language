import java.util.*; 

public class _339_Maximum_sum_non_adjacent_elements
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
		Maximum_sum_non_adjacent_elements(arr);
	}
	public static void Maximum_sum_non_adjacent_elements(int arr[])
	{
		int n = arr.length;
		int oinc = arr[0];
		int oexc = 0;
		int ninc = 0;
		int nexc = 0;
		for(int i=1;i<n;i++)
		{
			ninc = oexc+arr[i];
			nexc = (oinc > oexc)?oinc:oexc;
			oinc = ninc;
			oexc = nexc;
		}
		System.out.print(Math.max(ninc,nexc));

	}
}