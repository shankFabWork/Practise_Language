import java.util.*; 

public class _3_Is_a_number_prime
{
	public static void prime_or_not(int num)
    {
        int counter = 0;
        for(int i=2;i<num;i++)
        {
            if(num%i == 0)
            {
                counter++;
            }
        }
        if(counter == 0)
        {
            System.out.println("prime");
        }
        else
        {
            System.out.println("not prime");
        }
    }

    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for(int i=0;i<n;i++)
        {
            int num = scn.nextInt();
            prime_or_not(num);            
        }
    }
}