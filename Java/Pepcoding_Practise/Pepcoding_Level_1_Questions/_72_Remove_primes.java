import java.util.*; 

public class _72_Remove_primes
{
	public static boolean isPrime(int num)
	{
		int c = 0;
		for(int i=2;i<num;i++)
		{
			if(num%i == 0)
			{
				c++;
			}
		}
		if(c == 0)
		{
			return true;
		}
		return false;
	}

	public static void solution(ArrayList<Integer> al)
	{
		// Always run reverse loop as i will miss some values
		// for(int i=0;i<al.size();i++)
		// {
		// 	if(al.get(i)%2 != 0)
		// 	{
		// 		al.remove(i);
		// 	}
		// }
		// Like This
		// for(int i=al.size()-1;i>=0;i--)
		// {
		// 	if(al.get(i)%2 != 0)
		// 	{
		// 		al.remove(i);
		// 	}
		// }
	
		for(int i=al.size()-1;i>=0;i--)
		{
			if(isPrime(al.get(i)))
			{
				al.remove(i);
			}
		}
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		ArrayList<Integer> al = new ArrayList<>();
		for(int i = 0 ; i < n; i++){
			al.add(scn.nextInt());
		}
		solution(al);
		System.out.println(al);
	}
}