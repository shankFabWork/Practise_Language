import java.util.*; 

public class _30_Pattern_15
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int wide = 1;
        int space = n/2-1;
        int end = 1;
        for(int i=1;i<=n/2+1;i++)
        {
            for(int j=0;j<=space;j++)
            {
                System.out.print("\t");
            }
            for(int k=i;k<=wide;k++)
            {
                System.out.print(k+"\t");
            }
            for(int k=wide-1;k>=i;k--)
            {
                System.out.print(k+"\t");
            }
            wide += 2;
            space--;
            System.out.println();
        }
        space = 0;
        wide -= 4;
        for(int i=n/2;i>=1;i--)
        {
            for(int j=0;j<=space;j++)
            {
                System.out.print("\t");
            }
            for(int k=i;k<=wide;k++)
            {
                System.out.print(k+"\t");
            }
            for(int k=wide-1;k>=i;k--)
            {
                System.out.print(k+"\t");
            }
            wide -= 2;
            space++;
            System.out.println();
        }
    }
}