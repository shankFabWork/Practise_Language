import java.util.*; 

public class _11_String_Builder_Usage_and_Performance_Strings_and_Arraylists
{
	public static void main(String []args)
	{
		StringBuilder sb = new StringBuilder("hello");
		System.out.println(sb);
		char val = sb.charAt(0);
		System.out.println(val);
		// get character
		sb.setCharAt(0,'d');
		System.out.println(sb);
		// insert
		sb.insert(1,'c');
		System.out.println(sb);
		// delete
		sb.deleteCharAt(1);
		System.out.println(sb);
		// append
		sb.append('s');
		System.out.println(sb);
		// get string length
		System.out.println(sb.length());

		// Counting time for String class
		long s = System.currentTimeMillis();
		String s1 = "";
		for(int i=0;i<1000;i++)
		{
			s1 += i;
		}
		long e = System.currentTimeMillis();
		System.out.println(e-s);
		// Counting time for StringBuilder class
		s = System.currentTimeMillis();
		StringBuilder s2 = new StringBuilder();
		for(int i=0;i<1000;i++)
		{
			s2.append(i);
		}
		e = System.currentTimeMillis();
		System.out.println(e-s);
	}
}