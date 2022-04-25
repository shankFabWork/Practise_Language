import java.util.*; 

public class _33_Pattern_18
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int space = 0;
		int star = n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<space;j++)
			{
				System.out.print("\t");
			}
			for(int j=0;j<star;j++)
			{
				if(j > 0 && j < star-1 && i > 0 && i < n/2 )
				{
					System.out.print("\t");
				}
				else
				{
					System.out.print("*\t");
				}
			}
			if(i < n/2)
			{
				star -= 2;
				space++;	
			}
			else
			{
				star += 2;
				space--;
			}
			System.out.println();
		}
	}
}