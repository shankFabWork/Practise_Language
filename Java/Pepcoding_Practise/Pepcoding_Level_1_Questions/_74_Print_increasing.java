import java.util.*; 

public class _74_Print_increasing
{
	public static void Print_Decreasing(int n)
	{
		if(n == 0)
		{
			return;
		}
		Print_Decreasing(n-1);
		System.out.println(n);
	}
	public static void main(String []args)
	{
		Scanner scn  = new Scanner(System.in); 
		int n = scn.nextInt();
		Print_Decreasing(n);
	}
}