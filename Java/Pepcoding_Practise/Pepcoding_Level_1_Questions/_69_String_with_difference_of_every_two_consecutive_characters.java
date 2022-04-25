import java.util.*; 

public class _69_String_with_difference_of_every_two_consecutive_characters
{

	public static String solution(String str){
		// write your code here
		StringBuilder sb = new StringBuilder();
		sb.append(str.charAt(0));
		for(int i=1;i<str.length();i++)
		{
			char prev = str.charAt(i-1);
			char next = str.charAt(i);
			int diff = next - prev;
			sb.append(diff);
			sb.append(next);
		}
		return sb.toString();
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(solution(str));
	}

}