import java.util.*; 

public class _39_Any_base_to_any_base
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

	public static int Decimal_to_any_Base_Solution(int n, int b)
	{
		int temp_n = n;
		int res = 0;
		int counter = 0;
		while(temp_n != 0)
		{
			int rem = temp_n%b;
			res = res + rem * (int)Math.pow(10,counter);
			temp_n = temp_n/b;
			counter++;
		}
		return res;
	}

	public static int converted_value(int n,int b1,int b2)
	{
		int ans = Any_base_to_Decimal_Solution(n, b1);
		ans = Decimal_to_any_Base_Solution(ans, b2);
		return ans;
	}

	public static void main(String []args)
	{
		// convert the number n into its corresponding value in decimal number system.
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int b1 = scn.nextInt();
		int b2 = scn.nextInt();
		System.out.println(converted_value(n,b1,b2));
	}
}