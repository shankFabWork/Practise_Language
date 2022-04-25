import java.util.*; 

public class _100_N_Queens
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int arr[][] = new int[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[i][j] = 0;
			}
		}
		N_Queens_Problem(arr,0,"");
	}
	public static void N_Queens_Problem(int arr[][],int row,String str)
	{
		if(row == arr.length)
		{
			System.out.println(str+".");
			return;
		}
		for(int col=0;col<arr.length;col++)
		{
			if(queen_checker(arr,row,col) == true)
			{
				arr[row][col] = 1;
				N_Queens_Problem(arr,row+1, str+row+"-"+col+", ");
				arr[row][col] = 0;	
			}
		}
	}

	public static boolean queen_checker(int arr[][],int row,int col)
	{

		for(int i=0;i<row;i++)
		{
			if(arr[i][col] == 1)
			{
				return false;
			}
		}

		for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
		{
			if(arr[i][j] == 1)
			{
				return false;
			}
		}

		for(int i=row-1,j=col+1;i>=0 && j<arr.length;i--,j++)
		{
			if(arr[i][j] == 1)
			{
				return false;
			}
		}
		return true;
	}

}