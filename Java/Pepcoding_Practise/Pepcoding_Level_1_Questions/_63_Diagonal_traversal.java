// The State Of Wakanda - 2

import java.util.*; 

public class _63_Diagonal_traversal
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


        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                System.out.println(arr[i][j]);
            }
        }
    }
}