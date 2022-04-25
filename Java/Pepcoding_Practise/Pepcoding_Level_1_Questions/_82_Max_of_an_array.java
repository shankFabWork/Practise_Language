import java.util.*; 

public class _82_Max_of_an_array
{
	
	static int max_elem = Integer.MIN_VALUE;
    public static void main(String[] args) throws Exception {
        // write your code here
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i] = scn.nextInt();
		}
		int ans = maxOfArray(arr, 0);
		System.out.println(ans);
	}

    public static int maxOfArray(int[] arr, int idx){
		if(idx == arr.length)
		{
			return max_elem;
		}
		if(max_elem < arr[idx])
		{
			max_elem = arr[idx];
		}
		return maxOfArray(arr, idx+1);
    }
}