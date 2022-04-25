import java.util.*; 
// Not in Nados
public class _9_Armstrong_number
{
	public static void main(String []args)
	{
		int num = 1221;
		int temp_num = num;
		int res = 0;
		while(temp_num != 0)
		{
			int last_dig = temp_num%10;
			res = res*10+last_dig;
			temp_num = temp_num/10;
		}
		if(res == num)
		{
			System.out.println("number is palllindrome");
		}
		else
		{
			System.out.println("number is not palllindrome");
		}
	}
}