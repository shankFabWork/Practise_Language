import java.util.*; 

public class _57_2d_arrays_introduction_and_memory
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
        int r = scn.nextInt();
        int c = scn.nextInt();
		int arr[][] = new int[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				arr[i][j] = scn.nextInt();
			}	
		}

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				System.out.print(arr[i][j]+" ");
			}	
			System.out.println();
		}

		
	}
}