import java.util.*; 

public class _71_String_compression
{

	public static String compression1(String str){
		// write your code here
		StringBuilder sb = new StringBuilder();
		sb.append(str.charAt(0));
		for(int i=1;i<str.length();i++)
		{
			char prev = str.charAt(i-1);
			char next = str.charAt(i);
			if(prev != next)
			{
				sb.append(next);
			}
		}

		return sb.toString();
	}

	public static String compression2(String str)
	{
		StringBuilder sb = new StringBuilder();
		sb.append(str.charAt(0));
		int counter = 1;
		for(int i=1;i<str.length();i++)
		{
			char prev = str.charAt(i-1);
			char next = str.charAt(i);
			if(prev == next)
			{
				counter++;
			}
			else
			{
				if(counter > 1)
				{
					sb.append(counter);
					counter = 1;		
				}
				sb.append(next);
			}
		}
		if(counter > 1)
		{
			sb.append(counter);
		}
		return sb.toString();
	}
	public static void main(String[] args) 
	{
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(compression1(str));
		System.out.println(compression2(str));
	}
}