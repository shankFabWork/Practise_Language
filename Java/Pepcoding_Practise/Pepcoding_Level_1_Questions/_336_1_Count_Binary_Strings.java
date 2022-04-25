import java.util.*; 

public class _336_1_Count_Binary_Strings
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		// int arr0[] = new int[n+1];
		// int arr1[] = new int[n+1];
		// arr0[1] = 1;
		// arr1[1] = 1;
		// for(int i=2;i<n+1;i++)
		// {
		// 	arr0[i] = arr1[i-1];
		// 	arr1[i] = arr0[i-1]+arr1[i-1];
		// }
		// System.out.println(arr0[n]+arr1[n]);
		int oczeros = 1;
		int ocones = 1;
		int nczeros = 0;
		int ncones = 0;
		for(int i=2;i<=n;i++)
		{
			nczeros = ocones;
			ncones = ocones+oczeros;
			oczeros = nczeros;
			ocones = ncones;
		}
		System.out.print(nczeros+ncones);
	}
}