import java.util.*; 

public class _51_Inverse_an_array
{
	public static int[] Inverse_an_array(int arr[])
	{	
		int n = arr.length;
		int new_arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			new_arr[arr[i]] = i;
		}
		return new_arr;
	}
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
        int new_arr[] = Inverse_an_array(arr);
		for(int i=0;i<n;i++)
		{
			System.out.println(new_arr[i]);
		}
	}
}