import java.util.*; 

public class _341_Paint_fence
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		// No of fences
		int n = scn.nextInt();
		// No of colors
		int k = scn.nextInt();
		Paint_fence(n,k);
	}

	public static void Paint_fence(int n,int k)
	{
		int a = k*1;
		int b = k*(k-1);
		for(int i=3;i<=n;i++)
		{
			int temp_b = b;
			b = (k-1)*(a+b);
			a = temp_b;
		}
		System.out.print(a+b);
	}
}