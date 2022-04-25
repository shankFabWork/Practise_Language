import java.util.*; 

public class _440_Highway_Billboard_Medium
{
    public static int solution_1(int m , int[] x, int[] rev, int t) {
        // write your code here
		int n = x.length;
		int dp[] = new int[n];
		dp[0] = rev[0];
		int ans = dp[0];
		for(int i=1;i<n;i++)
		{
			int max_val = 0;
			for(int j=0;j<i;j++)
			{
				if(x[i]-x[j] > t)
				{
					max_val = Math.max(max_val,dp[j]);
				}
			}
			dp[i] = rev[i]+max_val;
			ans = Math.max(ans,dp[i]);
		}
		return ans;
	}

	public static int solution_2(int m,int x[],int revenue[],int t)
	{
		int n = x.length;
		HashMap <Integer,Integer> hm = new HashMap<>();
		for(int i=0;i<n;i++)
		{
			hm.put(x[i],revenue[i]);
		}
		int dp[] = new int[m];
		if(x[0] == 0)
		{
			dp[0] = 0;
		}
		for(int i=1;i<m;i++)
		{
			if(i-t-1 < 0)
			{
				dp[i] = dp[i-1];
			}
			else
			{
				if(dp[i-1] > hm.get(x[i])+dp[i-t-1])
				{
					dp[i] = dp[i-1];
				}
				else
				{
					dp[i] = hm.get(x[i])+dp[i-t-1];
				}	
			}
		}
		return dp[m-1];
	}

    public static void input(int []arr,Scanner scn){
        for(int i = 0;i<arr.length;i++){
            arr[i] = scn.nextInt();
        }
    }
    public static void main(String []args){
        Scanner scn = new Scanner(System.in);   
        int m = scn.nextInt();
        int n = scn.nextInt();
        
        int x[] = new int[n];
        input(x, scn);

        int revenue[] = new int[n];
        input(revenue,scn);

        int t = scn.nextInt();

        // System.out.println(solution_1(m, x, revenue, t));
        System.out.println(solution_2(m, x, revenue, t));
        scn.close();
    }	
}