import java.util.*; 

public class _91_Print_subsequence
{

	public static void printSS(String str,String add_str)
	{
		if(str.length() == 0)
		{
			System.out.println(add_str);
			return;
		}
		char ch = str.charAt(0);
		String ros = str.substring(1);
		printSS(ros,add_str+ch);
		printSS(ros,add_str+"");
	}

	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		printSS(str,"");
	}
}