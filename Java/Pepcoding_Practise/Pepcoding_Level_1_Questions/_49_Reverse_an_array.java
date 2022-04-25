import java.util.*; 

public class _49_Reverse_an_array
{
	public static void display(int[] a){
		StringBuilder sb = new StringBuilder();
	
		for(int val: a){
		  sb.append(val + " ");
		}
		System.out.println(sb);
	  }
	  
	  public static void swap(int a,int b)
	  {
		  int temp = a;
		  a = b;
		  b = temp;
	  }
	
	  public static void reverse(int[] a){
		int n = a.length;
		for(int i=0;i<n/2;i++)
		{
			int temp = a[i];
			a[i] = a[n-i-1];
			a[n-i-1] = temp;
		}
		
	  }
	
	public static void main(String[] args) throws Exception {
	
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++){
		   a[i] = scn.nextInt();
		}
	
		reverse(a);
		display(a);
	 }
}