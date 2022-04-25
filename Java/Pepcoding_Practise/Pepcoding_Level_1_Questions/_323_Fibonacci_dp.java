import java.util.*; 

public class _323_Fibonacci_dp
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		// int ans = fib_without_dp(n);
		// System.out.println(ans);
		int arr[] = new int[n+1];
		for(int i=0;i<n;i++)
		{
			arr[i] = -1;
		}
		fib_with_dp(n,arr);
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]);
		}
	}

	public static int fib_without_dp(int n)
	{
		if(n == 0 || n == 1)
		{
			return n;
		}
		System.out.print(n);
		int n1 = fib_without_dp(n-1);
		int n2 = fib_without_dp(n-2);
		return n1+n2;
	}

	public static int fib_with_dp(int n,int arr[])
	{
		if(n == 0 || n == 1)
		{
			return n;
		}
		if(arr[n] != -1)
		{
			return arr[n];
		}
		int n1 = fib_with_dp(n-1,arr);
		int n2 = fib_with_dp(n-2,arr);
		arr[n] = n1 + n2;
		return arr[n];		
	}
}