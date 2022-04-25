import java.util.*; 

public class _1_Print_Z
{
    public static void main(String[] args) {
		int n = 5;
		for (int j = 1; j <= n; j++)
		{
			System.out.print("*");
		}
		System.out.println();
		for (int i = 1; i <= n-2; i++)
		{
			for (int j = n-i-1; j >= 1; j--)
			{
				System.out.print(" ");
			}
			System.out.println("*");
		}
		for (int j = 1; j <= n; j++)
		{
			System.out.print("*");
		}
	}
}