import java.util.*; 

public class _149_Linkedlist_to_stack_adapter
{
	public static class LLToStackAdapter {
		LinkedList<Integer> list;
	
		public LLToStackAdapter() {
		  list = new LinkedList<>();
		}
	
		int size() {
			return list.size();
		}
	
		void push(int val) 
		{
			list.addFirst(val);
		}
	
		int pop() {
			if(size() == 0)
			{
				System.out.print("Stack Underflow");
				return -1;
			}
			else
			{
				return list.removeFirst();
			}
		}
	
		int top() {
			if(size() == 0)
			{
				System.out.print("Stack is Empty");
				return -1;
			}
			else
			{
				return list.getFirst();
			}
		}

		void disp()
		{
			for(int val:list)
			{
				System.out.print(val+" ");
			}
		}
	  }
	public static void main(String []args)
	{
		LLToStackAdapter ls = new LLToStackAdapter();
		ls.push(10);
		ls.push(20);
		ls.push(30);
		ls.push(40);
		ls.push(50);
		ls.pop();
		ls.disp();
		System.out.println();
		System.out.println(ls.top());
		System.out.println(ls.size());
	}
}