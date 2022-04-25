import java.util.*; 

public class _65_Saddle_price
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
                arr[i][j] = scn.nextInt();
            }    
        }

		for(int i=0;i<n;i++)
		{
			int sd = 0;
			for(int j=1;j<n;j++)
			{
				if(arr[i][j] < arr[i][sd])
				{
					sd = j;
				}
			}
			Boolean b = true;
			for(int k=0;k<n;k++)
			{
				if(arr[k][sd] > arr[i][sd])
				{
					b = false;
					break;
				}
			}
			if(b)
			{
				System.out.println(arr[i][sd]);
				return;
			}
		}
		System.out.println("Invalid input");
	}
}