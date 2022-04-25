import java.util.*; 

public class _123_Infix_conversions
{
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
		String str = "a*(b-c+d)/e";
		int n = str.length();
		Stack <String> pre = new Stack<>();
		Stack <String> post = new Stack<>();
		Stack <Character> operator = new Stack<>();
		for(int i=0;i<n;i++)
		{
			char ch = str.charAt(i);
			if(ch == ' ')
			{
				continue;
			}
			else if(ch == '(')
			{
				operator.push(ch);
			}
			else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				while(operator.size() != 0 && operator.peek() != '(' && precedence(operator.peek()) >= precedence(ch))
				{
					char op = operator.pop();

					String c_pre_1 = pre.pop(); 
					String c_pre_2 = pre.pop(); 
					pre.push(op+c_pre_2+c_pre_1); 

					String c_post_1 = post.pop(); 
					String c_post_2 = post.pop(); 
					post.push(c_post_2+c_post_1+op);
				}
				operator.push(ch);
			}
			else if(ch == ')')
			{
				while(operator.size() != 0 && operator.peek() != '(')
				{
					char op = operator.pop();

					String c_pre_1 = pre.pop(); 
					String c_pre_2 = pre.pop(); 
					pre.push(op+c_pre_2+c_pre_1);

					String c_post_1 = post.pop(); 
					String c_post_2 = post.pop(); 
					post.push(c_post_2+c_post_1+op);
				}
				operator.pop();
			}
			else if((ch >= 65 && ch <= 90 ) || (ch >= 97 && ch <= 122 ))
			{
				post.push(ch+"");
				pre.push(ch+"");
			}

		}


		while(operator.size() != 0)
		{
			char op = operator.pop();

			String c_pre_1 = pre.pop(); 
			String c_pre_2 = pre.pop(); 
			pre.push(op+c_pre_2+c_pre_1);

			String c_post_1 = post.pop(); 
			String c_post_2 = post.pop(); 
			post.push(c_post_2+c_post_1+op);
		}
		for(String s:post)
		{
			System.out.print(s+" ");
		}
		System.out.println();
		for(String s:pre)
		{
			System.out.print(s+" ");
		}


	}
}