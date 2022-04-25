import java.util.*; 

public class _73_Print_Decreasing
{
	public static void Print_Decreasing(int n)
	{
		if(n == 0)
		{
			return;
		}
		System.out.println(n);
		Print_Decreasing(n-1);
	}
	public static void main(String []args)
	{
		Scanner scn  = new Scanner(System.in); 
		int n = scn.nextInt();
		Print_Decreasing(n);
	}
}