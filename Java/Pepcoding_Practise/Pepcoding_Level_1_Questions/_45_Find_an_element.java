import java.util.*; 

public class _45_Find_an_element
{
	public static void main(String []args)
	{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			int a = scn.nextInt();
			arr[i] = a;
		}
		int elem = scn.nextInt();
		int idx = -1;
		for(int i=0;i<n;i++)
		{
			if(elem == arr[i])
			{
				idx = i;
				break;
			}
		}
		System.out.print(idx);

	}
}