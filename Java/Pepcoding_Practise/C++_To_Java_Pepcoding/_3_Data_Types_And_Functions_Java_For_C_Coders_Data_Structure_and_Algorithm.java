import java.util.*; 

public class _3_Data_Types_And_Functions_Java_For_C_Coders_Data_Structure_and_Algorithm
{

	public static void swap_num()
	{
		int temp = a;
		a = b;
		b = temp;
	}
	static int a = 10;
	static int b = 20;
	public static void main(String []args)
	{
		// byte short int long char float double
		System.out.println(a+" "+b);
		swap_num();
		System.out.println(a+" "+b);
	}
}