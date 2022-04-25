import java.util.*;

public class _59_Spiral_display {
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

        // int row = 3;
        // int column = 4;
		// int arr[][] = {
		// 	{11,12,13,14},
		// 	{21,22,23,24},
		// 	{31,32,33,34}
		// };

        int minr = 0;
        int maxr = row-1;
        int minc = 0;
        int maxc = column-1;
        int counter = 0;
        int no_elem = row * column;

        while(counter < no_elem)
        {
            for(int i=minr,j=minc;i<=maxr && counter < no_elem;i++)
            {
                System.out.println(arr[i][j]);
                counter++;
            }
            minc++;
            for(int i=maxr,j=minc;j<=maxc && counter < no_elem;j++)
            {
                System.out.println(arr[i][j]);
                counter++;
            }
            maxr--;
            for(int i=maxr,j=maxc;i>=minr && counter < no_elem;i--)
            {
                System.out.println(arr[i][j]);
                counter++;
            }
            maxc--;
            for(int i=minr,j=maxc;j>=minc && counter < no_elem;j--)
            {
                System.out.println(arr[i][j]);
                counter++;
            }
            minr++;
        }
        
	}
}
