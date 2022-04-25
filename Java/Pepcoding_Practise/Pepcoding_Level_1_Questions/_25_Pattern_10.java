import java.util.*; 

public class _25_Pattern_10
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n =  scn.nextInt();
		int space = n/2;
		int star = 1;
		int mid_space = 2;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<space;j++)
			{
				System.out.print("\t");
			}
			System.out.print("*");
			if(i != 0 && i != n-1)
			{
				for(int j=0;j<mid_space;j++)
				{
					System.out.print("\t");
				}
				System.out.print("*");
			}
			if(i != 0 && i != n-1 && i < n/2)
			{
				mid_space += 2;
			}
			else if(i != 0 && i != n-1 && i >= n/2)
			{
				mid_space -= 2;
			}
			if(i < n/2)
			{
				space--;
			}
			else
			{
				space++;
			}
			System.out.println();
		}
	}
}