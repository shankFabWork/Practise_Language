import java.util.*; 

public class _53_Print_all_subsets
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
		int limit = (int)Math.pow(2,n);
		for(int i=0;i<limit;i++)
		{
			String s = "";
			int num = i;
			for(int j = n-1;j>=0;j--)
			{
				int rem = num%2;
				num = num/2;
				if(rem == 0)
				{
					s = "-"+"\t"+s;
				}
				else
				{
					s = arr[j]+"\t"+s;
				}
			}
			System.out.println(s);
		}
	}
}