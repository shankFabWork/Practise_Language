import java.util.*; 

public class _324_Climb_stairs
{
	public static void main(String args[])
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int arr[] = new int[n+1];
		Climb_stairs(n,arr);
		System.out.println(arr[n]);
	}

	public static int Climb_stairs(int n,int arr[])
	{
		if(n == 0)
		{
			return 1;
		}
		else if(n < 0)
		{
			return 0;
		}
		if(arr[n] != 0)
		{
			return arr[n];
		}
		int a = Climb_stairs(n-1,arr);
		int b = Climb_stairs(n-2,arr);
		int c = Climb_stairs(n-3,arr);
		arr[n] = a+b+c;
		return arr[n];
	}
}