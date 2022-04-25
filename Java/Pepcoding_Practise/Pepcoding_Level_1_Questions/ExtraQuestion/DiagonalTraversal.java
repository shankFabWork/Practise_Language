import java.util.*;

public class DiagonalTraversal {
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
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println();
        }
    }
}

// 4
// 1 2 3 4
// 5 6 7 8 
// 9 10 11 12
// 13 14 15 16