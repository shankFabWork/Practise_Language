import java.util.*; 

public class _338_Count_a_b_c_subsequence
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		int n = str.length();
		int a = 0;
		int ab = 0;
		int abc = 0;
		for(int i=0;i<n;i++)
		{
			char ch = str.charAt(i);
			if(ch == 'a')
			{
				a = 2*a+1;
			}
			else if(ch == 'b')
			{
				ab = 2*ab+a;
			}
			else if(ch == 'c')
			{
				abc = 2*abc+ab;
			}
		}
		System.out.print(abc);
	}
}