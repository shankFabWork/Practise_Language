import java.util.*; 

public class _17_Pattern_2
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.print("*\t");
            }
            System.out.println();
        }
    }
}