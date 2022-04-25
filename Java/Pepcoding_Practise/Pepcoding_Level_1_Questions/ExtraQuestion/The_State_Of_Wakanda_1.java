import java.util.*;

public class The_State_Of_Wakanda_1 
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

        Boolean reverse = false;
        for(int j=0;j<c;j++)
        {
            if(reverse)
            {
                for(int i=r-1;i>=0;i--)
                {
                    System.out.println(arr[i][j]);
                }
            }
            else
            {
                for(int i=0;i<r;i++)
                {
                    System.out.println(arr[i][j]);
                }
            }
            reverse = !reverse;
        }

    }
    
}
