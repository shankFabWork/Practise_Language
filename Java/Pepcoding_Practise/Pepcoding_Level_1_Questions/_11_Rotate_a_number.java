import java.util.*; 

public class _11_Rotate_a_number
{
	public static int no_of_digit(int n)
	{
		int temp_n = n;
		int counter = 0;
		while(temp_n != 0)
		{
			temp_n = temp_n/10;
			counter++;
		}
		return counter;
	}

	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);

		int n = scn.nextInt();
		int k = scn.nextInt();
		int mul1 = 1;
		int mul2 = 1;
		int no_of_digit = no_of_digit(n);
		k = (k%no_of_digit<0)?(k%no_of_digit+no_of_digit):(k%no_of_digit);
		for(int i=1;i<=no_of_digit;i++)
		{
			if(i <= k)
			{
				mul1 *= 10;
			}
			else
			{
				mul2 *= 10;
			}
		}
		int q = n/mul1;
		int r = n%mul1;
		int res = r*mul2 + q;
		System.out.print(res);
	}
}