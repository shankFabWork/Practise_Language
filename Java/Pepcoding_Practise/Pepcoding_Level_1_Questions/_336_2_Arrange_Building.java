import java.util.*;

public class _336_2_Arrange_Building 
{
    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        long n = scn.nextInt();
		long ob = 1;
		long os = 1;
		long nb = 0;
		long ns = 0;
		for(long i=2;i<=n;i++)
		{
			nb = os;
			ns = os+ob;
			ob = nb;
			os = ns;
		}
		long tot = (nb+ns);
        System.out.print(tot*tot);
    }
}
