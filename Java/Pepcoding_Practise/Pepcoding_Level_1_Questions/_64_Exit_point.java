import java.util.*; 

public class _64_Exit_point
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);

        int row = scn.nextInt();
        int column = scn.nextInt();
        int arr[][] = new int[row][column];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                arr[i][j] = scn.nextInt();
            }    
        }
		int dir = 0;
		int i = 0;
		int j = 0;
		while(true)
		{
			dir = (dir + arr[i][j])%4;

			if(dir == 0)
			{
				j++;
			}
			else if(dir == 1)
			{
				i++;
			}
			else if(dir == 2)
			{
				j--;
			}
			else if(dir == 3)
			{
				i--;
			}

			if(i < 0)
			{
				i++;
				break;
			}
			else if(j < 0)
			{
				j++;
				break;	
			}
			else if(i == row)
			{
				i--;
				break;
			}
			else if(j == column)
			{
				j--;
				break;
			}
		}
		System.out.println(i);
		System.out.println(j);
	}
}