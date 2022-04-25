import java.util.*; 

public class _20_Pattern_5
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int sp = n/2;
        int st = 1;
        for(int i=1;i<=n;i++)
        {   
            for(int j=0;j<sp;j++)
            {
                System.out.print("\t");
            }
            for(int k=0;k<st;k++)
            {
                System.out.print("*\t");
            }
            if(i <= n/2)
            {
                sp--;
                st += 2;
            }
            else
            {
                sp++;
                st -= 2;
            }
            System.out.println();
        }
    }
}