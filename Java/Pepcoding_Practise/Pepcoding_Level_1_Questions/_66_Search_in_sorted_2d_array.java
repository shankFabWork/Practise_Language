import java.util.*; 

public class _66_Search_in_sorted_2d_array
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
		int elem = scn.nextInt();
		
		int i = 0;
		int j = n-1;
		while(i < n && j >= 0)
		{
			if(arr[i][j] == elem)
			{
				System.out.println(i);
				System.out.println(j);
				return;
			}
			else if(elem > arr[i][j])
			{
				i++;
			}
			else if(elem < arr[i][j])
			{
				j--;
			}
		}
		System.out.println("Not Found");
	}
}