import java.util.*; 

public class _77_Factorial
{
	

		public static void main(String[] args) throws Exception {
			Scanner scn = new Scanner(System.in);
			int n = scn.nextInt();
			int val = factorial(n);
			System.out.print(val);
		}
	
		public static int factorial(int n){
			if(n == 1)
			{
				return 1;
			}
			return n*factorial(n-1);
		}
}