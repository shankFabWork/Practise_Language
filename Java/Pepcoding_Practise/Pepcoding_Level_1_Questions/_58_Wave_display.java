import java.util.*; 

public class _58_Wave_display
{
	public static void main(String []args)
	{
		int arr[][] = {
			{1,2,3},
			{4,5,6},
		};
		Boolean b = true;
		int r = arr.length;
		int c = arr[0].length;
		for(int i=0;i<c;i++)
		{
			if(b)
			{
				for(int j=0;j<r;j++)
				{
					System.out.print(arr[j][i]+" ");
				}					
			}
			else
			{
				for(int j=r-1;j>=0;j--)
				{
					System.out.print(arr[j][i]+" ");
				}					
			}
			b = !b;
			// System.out.println();
		}
	}
}