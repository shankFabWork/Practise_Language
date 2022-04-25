import java.util.*; 

public class _5_Print_fibonacci
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int a = 0;
        int b = 1;
        System.out.println(0);
        System.out.println(1);
        n = n-2;
        while(n != 0)
        {
            int c = a+b;
            System.out.println(c);
            a = b;
            b = c;
            n = n-1;
        }
        
    }
}