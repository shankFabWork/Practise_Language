import java.util.*; 

public class _150_Linkedlist_to_queue_adapter
{
	public static class LLToQueueAdapter {
		LinkedList<Integer> list;
	
		public LLToQueueAdapter() {
		  list = new LinkedList<>();
		}
	
		int size() {
			return list.size();
		}
	
		void add(int val) {
			list.addLast(val);
		}
	
		int remove() 
		{
			if(size() == 0)
			{
				System.out.print("Queue underflow");
				return -1;
			}
			return list.removeFirst();
		}
	
		int peek() {
			if(size() == 0)
			{
				System.out.print("Queue underflow");
				return -1;
			}
			return list.getFirst();
		}
	  }
	public static void main(String []args)
	{

	}
}