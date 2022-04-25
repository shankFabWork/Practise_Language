import java.io.*;
import java.util.*;

// Input is managed for you
public class _119_Stock_span
{
	public static void display(int[] a){
		StringBuilder sb = new StringBuilder();
	
		for(int val: a){
		  sb.append(val + "\n");
		}
		System.out.println(sb);
	  }
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		for(int i = 0; i < n; i++){
		   a[i] = Integer.parseInt(br.readLine());
		}
	
		int[] span = solve(a);
		display(span);
	 }
	
	 // Main Code
	 public static int[] solve(int[] arr){
			int n = arr.length;
			int span[] = new int[n];
			Stack <Integer> s = new Stack<Integer>();
			s.push(0);
			span[0] = 1;
			// System.out.print(1+" ");
			for(int i=1;i<n;i++)
			{
				while(s.size() > 0 && arr[i] >= arr[s.peek()])
				{
					s.pop();
				}
				if(s.size() == 0)
				{
					span[i] = i+1;
					// System.out.print(i+1+" ");
				}
				else
				{
					span[i] = i-s.peek();
					// System.out.print(i-s.peek()+" ");
				}
				s.push(i);
			}
			return span;
	 }
}