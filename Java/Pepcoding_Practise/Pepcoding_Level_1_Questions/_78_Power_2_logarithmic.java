import java.util.Scanner;

public class _78_Power_2_logarithmic 
{
    public static int power(int x,int n)
    {
        if(n == 0)
        {
            return 1;
        }
        int xnb2 = power(x,n/2);
        int xn = xnb2*xnb2;
        if(n%2 == 1)
        {
            xn = xn*x;
        }
        return xn;
    }
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int x = scn.nextInt();
        int n = scn.nextInt();
        int ans = power(x,n);
        System.out.print(ans);

    }    
}
