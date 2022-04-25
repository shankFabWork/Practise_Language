import java.util.*; 

public class _68_Toggle_case
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		String str = scn.next();

		// Way 1
		// String res = "";
		// for(int i=0;i<str.length();i++)
		// {
		// 	if(str.charAt(i)>=65 && str.charAt(i)<=90)
		// 	{
		// 		res += (char)(str.charAt(i)+32);
		// 	}
		// 	else if(str.charAt(i)>=97 && str.charAt(i)<=122)
		// 	{
		// 		res += (char)(str.charAt(i)-32);
		// 	}
		// }
		// System.out.print(res);

		// Way2 [StringBuilder Efficient]
		StringBuilder sb = new StringBuilder(str);
		for(int i=0;i<sb.length();i++)
		{
			if(sb.charAt(i) >= 'a' && sb.charAt(i) <= 'z')
			{
				sb.setCharAt(i,(char)(sb.charAt(i)-'a'+'A'));
			}
			else if(sb.charAt(i) >= 'A' && sb.charAt(i) <= 'Z')
			{
				sb.setCharAt(i,(char)(sb.charAt(i)-'A'+'a'));
			}
		}
		System.out.print(sb.toString());
	}
}