import java.util.*;
import java.math.BigInteger;

public class asdf 
{
    // O(1)
    public static long fourthPowerSum(int n)
    {
        return ((6 * n * n * n * n * n) +
                (15 * n * n * n * n) +
                (10 * n * n * n) - n) / 30;
    }


    public static BigInteger factorial(int N)
    {
        BigInteger f = new BigInteger("1"); 
            
        for (int i = 1; i <= N; i++)
            f = f.multiply(BigInteger.valueOf(i));
 
        return f;
    }

    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        while(t != 0)
        {
            int n = scn.nextInt();
            
            long a = fourthPowerSum(n);

            BigInteger sum = BigInteger.valueOf(a);
            BigInteger prod = factorial(n);
            
            // System.out.println(sum+" "+prod);
            BigInteger a1
                = new BigInteger(sum.toString());
            BigInteger b1
                = new BigInteger(prod.toString());
    
            // Calculate gcd
            BigInteger result = a1.gcd(b1);
            System.out.println(result);
            t=t-1;
        }
    }    
}
