import java.util.*;

import javax.management.ImmutableDescriptor; 

public class _10_String_Interning_and_Immutability_Strings_and_StringBuilders_in_JAVA
{
	public static void main(String []args)
	{
		String s1 = "hello";
		String s2 = "hello";
		// s1 and s2 make string in heap area 
		// know as interning pool
		// use of interning - saving memory
		String s3 = new String("hello");
		// s3 will have not interning as it will make 
		// address in new location
		
		System.out.println(s1 == s2);
		System.out.println(s1 == s3);

		System.out.println(s1.equals(s2));
		System.out.println(s1.equals(s3));

		// 1) Comparision
		// 2) Immutabile

	}
}