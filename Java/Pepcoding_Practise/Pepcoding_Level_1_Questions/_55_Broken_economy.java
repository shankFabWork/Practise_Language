import java.util.*; 

public class _55_Broken_economy
{
	public static void main(String []args)
	{	
		Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i] = scn.nextInt();
		}
        int d = scn.nextInt();

		int ceil = 0;
		int floor = 0;
		int l = 0;
		int h = n-1;
		while(l <= h)
		{
			int mid = (l+h)/2;
			if(arr[mid] > d)
			{
				ceil  = arr[mid];
				h = mid - 1;
			}
			else if(arr[mid] < d)
			{
				floor = arr[mid];
				l = mid + 1;
			}
			else
			{
				ceil = arr[mid];
				floor = arr[mid];
				break;
			}
		}
		System.out.println(ceil);
		System.out.println(floor);
	}
}