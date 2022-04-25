import java.util.*; 

public class _41_Any_base_substraction
{
	public static int getDifference(int b, int n1, int n2)
	{
		int c = 0;
		int res = 0;
		int p = 1;
		int ans = 0;
		while(n2 > 0)
		{
			int l1 = n1%10;
			int l2 = n2%10;
			l2 = l2 + c;
			if(l1 > l2)
			{
				c = -1;
				l2 = l2 + b;
				ans = l2 - l1;
			}
			else
			{
				c = 0;
				ans = l2 - l1;
			}
			res = res + ans*p;
			p = p*10;
			n1 = n1/10;
			n2 = n2/10;
		}
		return res;
	}
	
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int b = scn.nextInt();
		int n1 = scn.nextInt();
		int n2 = scn.nextInt();
		int d = getDifference(b, n1, n2);
		System.out.println(d);		
	}
}