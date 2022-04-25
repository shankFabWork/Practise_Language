import java.util.*; 

public class _117_Balanced_brackets
{

	public static Boolean bracket_checker(Stack <Character> sta,char cb)
	{
		if(sta.size() == 0)
		{
			return false;
		}
		else if(sta.peek() != cb)
		{
			return false;					
		}
		else
		{
			sta.pop();
		}
		return true;
	}

	public static void main(String []args)
	{
		// 1) When there is a missmatch
		// 2) when there is more closing brackets
		// 3) when there is more opening brackets

		Scanner scn = new Scanner(System.in);
		Stack<Character> sta = new Stack<Character>();
        String str = scn.nextLine();

		for(int i=0;i<str.length();i++)
		{
			char ch = str.charAt(i);

			if(ch == '(' || ch == '[' || ch == '{')
			{
				sta.push(ch);
			}
			else if(ch == ')')
			{
				boolean res = bracket_checker(sta,'(');
				if(res == false)
				{
					System.out.print(res);
					return;
				}
			}
			else if(ch == ']')
			{
				boolean res = bracket_checker(sta,'[');
				if(res == false)
				{
					System.out.print(res);
					return;
				}
			}
			else if(ch == '}')
			{
				boolean res = bracket_checker(sta,'{');
				if(res == false)
				{
					System.out.print(res);
					return;
				}
			}
		}
		if(sta.size() == 0)
		{
			System.out.print(true);
			return;
		}
		else
		{
			System.out.print(false);
			return;
		}

		
	}
}