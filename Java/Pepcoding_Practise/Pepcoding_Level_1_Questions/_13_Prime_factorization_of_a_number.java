import java.util.*; 

public class _13_Prime_factorization_of_a_number
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int temp_n = n;
		for(int div = 2;div < Math.sqrt(n);div++)
		{
			while(temp_n%div == 0)
			{
				System.out.print(div+" ");
				temp_n = temp_n/div;
			}
		}
		if(temp_n != 1)
		{
			System.out.print(temp_n);
		}
	}
}