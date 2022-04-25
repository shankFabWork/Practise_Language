import java.util.*; 

public class _122_Infix_evaluations
{
	public static int perform_operation(int b,int a,char oprtor)
	{
		if(oprtor == '+')
		{
			return b+a;
		}
		else if(oprtor == '-')
		{
			return b-a;
		}
		else if(oprtor == '*')
		{
			return b*a;
		}
		else if(oprtor == '/')
		{
			return b/a;
		}
		return 0;
	}

	public static int precedence(char ch)
	{
		if(ch == '+')
		{
			return 1;
		}
		else if(ch == '-')
		{
			return 1;
		}
		else if(ch == '*')
		{
			return 2;
		}
		else if(ch == '/')
		{
			return 2;
		}
		return 0;
	}

	public static void main(String []args)
	{
		String str = "2 + 6 * 4 / 8 - 3";
		int n = str.length();

		Stack <Character> operator = new Stack<>();
		Stack <Integer> operand = new Stack<>();

		for(int i=0;i<n;i++)
		{
			char ch = str.charAt(i);
			if(ch == ' ')
			{
				continue;
			}
			else if(ch == '(')
			{
				operator.push('(');
			}
			else if(ch >= '0' && ch <= '9')
			{
				operand.push(ch-'0');
			}
			else if(ch == ')')
			{
				while(operator.size() != 0 && operator.peek() != '(')
				{
					int a = operand.pop();
					int b = operand.pop();
					char oprtor = operator.pop();
					int ans = perform_operation(b,a,oprtor);
					operand.push(ans);
				}
				operator.pop();
			}
			else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				while(
					operator.size() != 0 
					&& 
					precedence(operator.peek()) >= precedence(ch) 
					&& 
					operator.peek() != '('
				)
				{
						int a = operand.pop();
						int b = operand.pop();
						char oprtor = operator.pop();
						int ans = perform_operation(b,a,oprtor);
						operand.push(ans);
				}
				operator.push(ch);
			}

		}
		
		while(operator.size() != 0)
		{
			int a = operand.pop();
			int b = operand.pop();
			char oprtor = operator.pop();
			int ans = perform_operation(b,a,oprtor);
			operand.push(ans);
		}
		System.out.print(operand.peek());
		
	}
}