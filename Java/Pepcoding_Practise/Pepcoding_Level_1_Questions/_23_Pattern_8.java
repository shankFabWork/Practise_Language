import java.util.*; 

public class _23_Pattern_8
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+j+1 == n)
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print("\t");
                }
            }
            System.out.println();
        }

    }
}