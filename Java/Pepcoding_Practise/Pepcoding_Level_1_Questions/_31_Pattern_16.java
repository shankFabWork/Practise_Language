import java.util.*; 

public class _31_Pattern_16
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n =  scn.nextInt();
		int space = 2*(n)-3;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				System.out.print(j+"\t");
			}
			for(int j=1;j<=space;j++)
			{
				System.out.print("\t");
			}
			for(int j=i;j>=1;j--)
			{
				if(i == n && j == i)
				{
				}
				else
				{
					System.out.print(j+"\t");
				}
			}
			System.out.println();
			space = space-2;
		}
	}
}