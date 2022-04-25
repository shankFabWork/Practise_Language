import java.util.*; 

public class _15_The_curious_case_of_benjamin_bulbs
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int num = scn.nextInt();
		int counter = 0;
		for(int i=1;i*i<=num;i++)
		{
			System.out.println(i*i);
		}
	}
}