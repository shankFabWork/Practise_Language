import java.util.*; 

public class _120_Largest_area_histogram
{
	public static void main(String []args)
	{

		int arr[] = {6,2,5,4,5,1,6};
        int n = arr.length;

        // nse [next smaller element]
        // nse in left and right

        // nse in left
        Stack <Integer> sta = new Stack <Integer>();

        int lb[] = new int[n];
        lb[0] = -1;
        sta.push(0);
        for(int i=1;i<n;i++)
        {
            while(sta.size() != 0 && arr[i] <= arr[sta.peek()])
            {
                sta.pop ();
            }
            if(sta.size() == 0)
            {
                lb[i] = -1;
            }
            else if(arr[i] > arr[sta.peek()])
            {
                lb[i] = sta.peek();
            }
            sta.push(i);
        }

        int rb[] = new int[n];
        rb[n-1] = n;
        sta.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(sta.size() != 0 && arr[i] <= arr[sta.peek()])
            {
                sta.pop();
            }
            if(sta.size() == 0)
            {
                rb[i] = n;
                sta.push(i);
            }
            else if(arr[sta.peek()] < arr[i])
            {
                rb[i] = sta.peek();
                sta.push(i);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int width = rb[i]-lb[i]-1;
            if(ans < width*arr[i])
            {
                ans = width*arr[i];
            }
        }
        System.out.print(ans);


	}	
}