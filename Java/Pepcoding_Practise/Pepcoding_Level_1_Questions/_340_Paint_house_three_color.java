import java.util.*; 

public class _340_Paint_house_three_color
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();

		// 1 - using three array
		// int red[] = new int[n];
		// int blue[] = new int[n];
		// int green[] = new int[n];
		// for(int i=0;i<n;i++)
		// {
		// 	red[i] = scn.nextInt();
		// 	blue[i] = scn.nextInt();
		// 	green[i] = scn.nextInt();
		// }
		// Paint_house_three_color_1(red,blue,green);

		// 2 - using one matrix
		int arr[][] = new int[3][n];
		for(int i=0;i<n;i++)
		{
			arr[0][i] = scn.nextInt(); 
			arr[1][i] = scn.nextInt(); 
			arr[2][i] = scn.nextInt(); 
		}
		Paint_house_three_color_2(arr);
	}

	public static void Paint_house_three_color_1(int red[],int blue[],int green[])
	{
		int or =red[0];
		int ob =blue[0];
		int og =green[0];
		int n = red.length;
		for(int i=1;i<n;i++)
		{
			int nr = red[i]+Math.min(ob,og);
			int nb = blue[i]+Math.min(or,og);
			int ng = green[i]+Math.min(or,ob);
			or = nr;
			ob = nb;
			og = ng;
		}
		System.out.print(Math.min(or,Math.min(ob,og)));
	}

	public static void Paint_house_three_color_2(int arr[][])
	{
		int r = arr.length;
		int c = arr[0].length;
		int dp[][] = new int[r][c];
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[2][0] = arr[2][0];
		for(int i=1;i<c;i++)
		{
			dp[0][i] = arr[0][i] + Math.min(dp[1][i-1],dp[2][i-1]);
			dp[1][i] = arr[1][i] + Math.min(dp[0][i-1],dp[2][i-1]);
			dp[2][i] = arr[2][i] + Math.min(dp[0][i-1],dp[1][i-1]);
		}
		System.out.println(Math.min(dp[0][c-1],Math.min(dp[1][c-1],dp[2][c-1])));
	}
}