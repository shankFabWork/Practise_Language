import java.util.*; 

public class _4_Print_all_primes_till_n
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int s = scn.nextInt();
		int e = scn.nextInt();
		int c = 0;
		for(int i=s;i<=e;i++)
		{
			// j*j is important
			for(int j=2;j*j<=i;j++)
			{
				if(i%j == 0)
				{
					c++;
					break;
				}
			}
			if(c == 0)
			{
				System.out.println(i);
			}	
			c = 0;
		}
	}
}