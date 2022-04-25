import java.util.*; 

public class _84_Last_index
{

    public static void main(String[] args) throws Exception {
        // write your code here
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i] = scn.nextInt();
		}
		int x = scn.nextInt();
		int and = lastIndex(arr,arr.length-1,x);
		System.out.println(and);
    }

    public static int lastIndex(int[] arr, int idx, int x){
		if(idx < 0)
		{
			return -1;
		}
		if(arr[idx] == x)
		{
			return idx;
		}
		else
		{
			return lastIndex(arr, idx-1, x);
		}
    }
}