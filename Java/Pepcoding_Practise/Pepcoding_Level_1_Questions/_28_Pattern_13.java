import java.util.*; 

public class _28_Pattern_13
{
	public static int fact(int num)
	{
		int a = 1;
		for(int i=1;i<=num;i++)
		{
			a = a*i;
		}
		return a;
	}

	public static int combination(int a,int b)
	{
		int ans = fact(a)/(fact(b)*fact(a-b));
		return ans;
	}

	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				System.out.print(combination(i, j)+"\t");
			}	
			System.out.println();
		}
	}
}