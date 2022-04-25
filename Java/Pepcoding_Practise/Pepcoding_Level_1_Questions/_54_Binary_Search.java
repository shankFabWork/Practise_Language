import java.util.*; 

// Not in portal to solve
public class _54_Binary_Search
{
	public static void main(String []args)
	{
		int arr[] = {10,20,30};
		int elem = 20;
		int n = arr.length;
		int l = 0;
		int h = n-1;
		int mid = 0;
		while(l <= h)
		{
			mid = (l+h)/2;
			if(arr[mid] == elem)
			{
				break;
			}
			if(arr[mid] > elem)
			{
				h = mid - 1;
			}
			else 
			{
				l = mid + 1;
			}
		}
		System.out.println(mid);
	}
}