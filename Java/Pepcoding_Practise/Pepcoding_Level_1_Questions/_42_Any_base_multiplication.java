import java.util.*; 

public class _42_Any_base_multiplication
{
	public static int base_addition(int b, int n1, int n2)
	{
		int c = 0;
		int q = 0;
		int res = 0;
		// int counter = 0;
		int p = 1;
		while(n1 != 0 || n2 != 0 || c != 0)
		{
			int d1 = n1%10;
			int d2 = n2%10;
			c = (d1 + d2) + q;
			q = c/b;
			int rem = c%b;
			// res = res + rem * (int)Math.pow(10,counter);
			res = res + rem * p;
			p = p*10;
			n1 = n1/10;
			n2 = n2/10;
			// counter++;
		}
		return res;
	}

	public static int getSingleProduct(int b,int n1,int d2)
	{
		int c = 0;
		int res = 0;
		int p = 1;
		while(n1 > 0 || c > 0)
		{
			int d1 = n1%10;
			n1 = n1/10;
			int d = d1*d2+c;
			c = d/b;
			int rem = d%b;
			res = res + rem*p;
			p = p * 10;
		}
		return res;
	}

	public static int getProduct(int b, int n1, int n2)
	{
		int res = 0;
		int p = 1;
		while(n2 > 0)
		{
			int d2 = n2%10;
			n2 = n2/10;
			int ans = getSingleProduct(b,n1,d2);
			res = base_addition(b,res,ans*p);
			p = p*10;
		}
		return res;
	}
   
   public static void main(String[] args) {
	   Scanner scn = new Scanner(System.in);
	   int b = scn.nextInt();
	   int n1 = scn.nextInt();
	   int n2 = scn.nextInt();
   
	   int d = getProduct(b, n1, n2);
	   System.out.println(d);
	}
   
}