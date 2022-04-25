import java.util.*; 

public class _50_Rotate_an_array
{
	public static void Rotate_an_array(int arr[],int i,int j)
	{
		while(i <= j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
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
        int k = scn.nextInt();
		if(k < 0)
		{
			k = (k%n)+n;
		}
		else
		{
			k = (k%n);
		}

        Rotate_an_array(arr,0,n-k-1);
        Rotate_an_array(arr,n-k,n-1);
        Rotate_an_array(arr,0,n-1);
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]+" ");
		}
	}
}