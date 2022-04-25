import java.util.*; 

public class _27_Pattern_12
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n =  scn.nextInt();
		int a = -1;
		int b = 1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				int c = a + b;
				System.out.print(c+"\t");
				a = b;
				b = c;
			}
			System.out.println();
		}
	}
}