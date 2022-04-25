import java.util.*; 

public class _67_String_theory
{
	public static boolean pallindome_check(String str)
	{
		int s = 0;
		int e = str.length()-1;
		while(s <= e)
		{
			if(str.charAt(s) != str.charAt(e))
			{
				return false;
			}
			s++;
			e--;
		}
		return true;
	}

	public static void solution(String str){
		//write your code here
		for(int i=0;i<str.length();i++)
		{
			for(int j=i+1;j<=str.length();j++)
			{
				String new_str = str.substring(i,j);
				if(pallindome_check(new_str))
				{
					System.out.println(new_str);
				}
			}
		}
		
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		solution(str);
	}
}