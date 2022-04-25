import java.util.*; 

public class _9_Introduction_to_Strings_StringBuilders_and_Arraylists_in_JAVA
{
	public static void main(String []args)
	{
		String s1 = "shank";
		System.out.println(s1);
		System.out.println(s1.charAt(0));
		for(int i=0;i<s1.length();i++)
		{
			char a = s1.charAt(i);
			System.out.print(a+" ");
		}
		System.out.println();
		
		// Substring (0,n-1)
		System.out.println(s1.substring(1,4) );
		System.out.println(s1.substring(1,1) ); // nothing

		System.out.println("Print all substring of a string");
		for(int i=0;i<s1.length();i++)
		{
			for(int j=i+1;j<=s1.length();j++)
			{
				System.out.println(s1.substring(i,j));
			}	
		}
		System.out.println("Concat");
		String s4 = "rahul";
		s4 += " ";
		s4 += 65;
		String s5 = "sharma";
		String s6 = s4+s5;
		System.out.println(s6); 
		System.out.println("Hello"+10+20); 
		System.out.println(10+20+"Hello");
		
		System.out.println("Split :-");
		String data = "shank rajan pankaj gagan";
		String[] data_arr = data.split(" ");
		for(int i=0;i<data_arr.length;i++)
		{
			System.out.println(data_arr[i]);
		}

		

		// Scanner scn = new Scanner(System.in);
		// String s2 = scn.nextLine();
		// System.out.println(s2);
		// String s3 = scn.next();
		// System.out.println(s3);
	}
}