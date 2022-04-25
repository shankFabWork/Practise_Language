import java.util.*; 

public class _4_Arrays_Java_For_C_Coders_Data_Structure_and_Algorithm
{
	public static void main(String []args)
	{
		int arr[] = new int[5];
		for(int i=0;i<arr.length;i++)
		{
			arr[i] = (i+1)*10;
		}
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println();
		for(int data:arr)
		{
			System.out.print(data+" ");
		}

	}
}