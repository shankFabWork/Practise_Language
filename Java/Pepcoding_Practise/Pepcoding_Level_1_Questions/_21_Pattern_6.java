import java.util.*; 

public class _21_Pattern_6
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int sp = 1;
        int st = n/2+1;
        for(int i=1;i<=n;i++)
        {   
            for(int j=1;j<=st;j++)
            {
                System.out.print("*\t");
            }
            for(int k=1;k<=sp;k++)
            {
                System.out.print("\t");
            }
            for(int s=1;s<=st;s++)
            {
                System.out.print("*\t");
            }
            // System.out.print(st+" "+sp+" "+st);
            if(i <= n/2)
            {
                sp += 2;
                st -= 1;
            }
            else
            {
                sp -= 2;
                st += 1;
            }
            System.out.println();
        }
    }
}