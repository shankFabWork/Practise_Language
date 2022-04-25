import java.util.*; 

public class _121_Sliding_window_max
{
	public static void main(String []args)
	{

		int arr[] = {2,9,3,8,1,7,12,6,14,4,32,0,7,19,8,12,6};
		int n = arr.length;
		int k = 4;	

		int nge_r[] = new int[n];
		Stack <Integer> sta = new Stack<>();

		nge_r[n-1] = n;
		sta.push(n-1);

		for(int i=n-2;i>=0;i--)
		{
			while(sta.size() != 0 && arr[i] >= arr[sta.peek()])
			{
				sta.pop();
			}
			if(sta.size() == 0 )
			{
				nge_r[i] = n;
				sta.push(i);
			}
			else if(arr[sta.peek()] > arr[i])
			{
				nge_r[i] = sta.peek();
				sta.push(i);
			}
		}

		for(int i=0;i<=n-k;i++)
		{
			int j = i;
			while(nge_r[j] < i+k)
			{
				j = nge_r[j];
			}
			System.out.println(arr[j]);
		}

	}
}