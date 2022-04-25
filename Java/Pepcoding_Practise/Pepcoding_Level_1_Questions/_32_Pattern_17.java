import java.util.*; 

public class _32_Pattern_17
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int space = n/2;
		int star = 1;
		for(int i=0;i<n;i++)
		{
			if(i == n/2)
			{
				for(int j=0;j<space;j++)
				{
					System.out.print("*\t");
				}	
			}
			else
			{
				for(int j=0;j<space;j++)
				{
					System.out.print("\t");
				}
			}
			for(int k=0;k<star;k++)
			{
				System.out.print("*\t");
			}
			if(i<n/2)
			{
				star++;
			}
			else
			{
				star--;
			}
			System.out.println();
		}
	}
}