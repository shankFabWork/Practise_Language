import java.util.*; 

public class _26_Pattern_11
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n =  scn.nextInt();
		int s = 1;
		for(int i=0;i<n;i++)
		{
			for(int j=s;j<=s+i;j++)
			{
				System.out.print(j+"\t");
			}
			s = s+i+1;
			System.out.println();
		}
	}
}