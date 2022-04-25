import java.util.*; 

public class _37_Decimal_to_any_base
{
  
	public static int reverse(int n)
	{
		int temp_n = n;
		int res = 0;
		while(temp_n != 0)
		{
			int last_dig = temp_n%10;
			res = res*10 + last_dig;
			temp_n = temp_n/10;
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
  public static void main(String[] args) 
  {
      Scanner scn = new Scanner(System.in);
      int n = scn.nextInt();
      int b = scn.nextInt();
      int dn = Decimal_to_any_Base_Solution(n, b);
      System.out.println(dn);
   }
}