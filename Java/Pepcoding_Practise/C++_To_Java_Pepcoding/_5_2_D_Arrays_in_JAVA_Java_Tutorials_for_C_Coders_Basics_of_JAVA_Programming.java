import java.util.*; 

public class _5_2_D_Arrays_in_JAVA_Java_Tutorials_for_C_Coders_Basics_of_JAVA_Programming
{
	public static void main(String []args)
	{
		String arr[][] = new String[2][2];
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr[i].length;j++)
			{
				arr[i][j] = i+""+j;
			}	
		}

		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr[i].length;j++)
			{
				System.out.println(arr[i][j]);
			}	
		}
		
		System.out.println();
		int new_arr[][] = {
			{1,2,3},
			{3,4}
		};
		for(int i=0;i<new_arr.length;i++)
		{
			for(int j=0;j<new_arr[i].length;j++)
			{
				System.out.println(new_arr[i][j]);
			}	
		}

	}
}