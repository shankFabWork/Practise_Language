import java.util.*; 

public class _47_Sum_of_two_arrays
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

		int i = n1 - 1;
		int j = n2 - 1;
		int k = (n1 > n2)?n1-1:n2-1;
		int res[] = new int[k+1];

		int c = 0;
		int d = 0;
		int rem = 0;
		while(k >= 0)
		{
			d = c;
			if(i >= 0)
			{
				d += arr1[i];
			}
			if(j >= 0)
			{
				d += arr2[j];
			}
			c = d/10;
			rem = d%10;
			res[k] = rem;
			i--;
			j--;
			k--;
		}
		if(c != 0)
		{
			System.out.println(c);
		}
		for(int data:res)
		{
			System.out.println(data);
		}
	}
}