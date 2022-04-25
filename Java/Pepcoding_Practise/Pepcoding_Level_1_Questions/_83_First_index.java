import java.util.*; 

public class _83_First_index
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
		int and = firstIndex(arr,0,x);
		System.out.println(and);
	}

    public static int firstIndex(int[] arr, int idx, int x){
		if(idx == arr.length)
		{
			return -1;
		}
		if(arr[idx] == x)
		{
			return idx;
		}
		else
		{
			return firstIndex(arr, idx+1, x);
		}
    }
}