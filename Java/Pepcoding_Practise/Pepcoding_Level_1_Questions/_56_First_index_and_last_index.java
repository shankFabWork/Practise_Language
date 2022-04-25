import java.util.*; 

public class _56_First_index_and_last_index
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
        int d = scn.nextInt();

		int l = 0;
		int h = n-1;
		int fi = -1;
		while(l <= h)
		{
			int mid = (l+h)/2;
			if(arr[mid] > d)
			{
				h = mid - 1;
			}
			else if(arr[mid] < d)
			{
				l = mid + 1;
			}
			else
			{
				fi = mid;
				h = mid - 1;
			}
		}

		l = 0;
		h = n - 1;
		int li = -1;

		while(l <= h)
		{
			int mid = (l+h)/2;
			if(arr[mid] > d)
			{
				h = mid - 1;
			}
			else if(arr[mid] < d)
			{
				l = mid + 1;
			}
			else
			{
				li = mid;
				l = mid + 1;
			}
		}

		System.out.println(fi);
		System.out.println(li);

	}
}