import java.util.*; 

public class _48_Difference_of_two_arrays
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		
		int n1 = scn.nextInt();		
		int arr1[] = new int[n1];
		for(int i=0;i<n1;i++)
		{
			int a = scn.nextInt();
			arr1[i] = a;
		}

		int n2 = scn.nextInt();
		int arr2[] = new int[n2];
		for(int i=0;i<n2;i++)
		{
			int a = scn.nextInt();
			arr2[i] = a;
		}
		
		int gre_size = n1>n2?n1:n2;
		int res[] = new int[gre_size];
		int i = n1 - 1;
		int j = n2 - 1;
		int k = gre_size - 1;

		int c = 0;
		int d = 0;
		while(k >= 0)
		{
			int arr1_val = (i >= 0 )?arr1[i]:0;
			if(arr2[j] + c >= arr1_val)
			{
				d = arr2[j] + c - arr1_val;
				c = 0;
			}
			else
			{
				d = (arr2[j]+c+10) - arr1_val;
				c = -1;
			} 
			// System.out.println(i+" "+j+" "+k);
			res[k] = d;
			i--;
			j--;
			k--;
		}

		Boolean isShow = false;
		for(int g=0;g<gre_size;g++)
		{
			if(res[g] != 0)
			{
				isShow = true;
			}
			if(isShow)
			{
				System.out.println(res[g]);
			}
		}

		// Boolean isShow = false;
		// for(int data:res)
		// {
		// 	if(data != 0)
		// 	{
		// 		isShow = true;
		// 	}
		// 	if(isShow)
		// 	{
		// 		System.out.println(data);
		// 	}
		// }

	}
}