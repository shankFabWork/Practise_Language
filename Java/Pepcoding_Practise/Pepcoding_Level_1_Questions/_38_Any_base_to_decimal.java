import java.util.*; 

public class _38_Any_base_to_decimal
{
	public static int Any_base_to_Decimal_Solution(int n,int b)
	{
		int temp_n = n;
		int res = 0;
		int counter = 0;
		while(temp_n > 0)
		{
			int rem = temp_n%10;
			res = res + rem*(int)Math.pow(b,counter);
			temp_n = temp_n/10;
			counter++;
		}
		return res;
	}

	public static void main(String []args)
	{
		// convert the number n into its corresponding value in decimal number system.
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int b = scn.nextInt();
		System.out.println(Any_base_to_Decimal_Solution(n,b));
	}
}