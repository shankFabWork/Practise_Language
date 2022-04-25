import java.util.Scanner;

public class _35_1_Pattern_M 
{
    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i <= n/2+1)
                {
                    if(j == 1 || j == n || i == j || (i+j == n+1))
                    {
                        System.out.print("*\t");
                    }    
                    else
                    {
                        System.out.print("\t");
                    }
                }
                else
                {
                    if(j == 1 || j == n)
                    {
                        System.out.print("*\t");
                    }    
                    else
                    {
                        System.out.print("\t");
                    }
                }
            }
            System.out.println();
        }
    }    
}
