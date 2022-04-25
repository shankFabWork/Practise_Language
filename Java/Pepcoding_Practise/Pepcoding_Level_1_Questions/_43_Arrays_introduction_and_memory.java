import java.util.*; 

public class _43_Arrays_introduction_and_memory
{
	public static void swap_array_elem(int arr[],int i,int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void main(String []args)
	{
		int arr[] = new int[5];
		arr[0] = 10;
		arr[1] = 23;
		arr[2] = 21;
		arr[3] = 54;
		arr[4] = 15;
		int two[] = arr;
		two[3] = 200;
		for(int i=0;i<two.length;i++)
		{
			System.out.print(two[i]+" ");
		}
		System.out.println();
		swap_array_elem(two, 0, 1);
		for(int i=0;i<two.length;i++)
		{
			System.out.print(two[i]+" ");
		}
		System.out.println();
		// shallow copy
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+" ");
		}
	}
}