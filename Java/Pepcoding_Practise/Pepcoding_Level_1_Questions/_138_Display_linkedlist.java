import java.util.*; 

public class _138_Display_linkedlist
{
	public static class Node
	{
		int data;
		Node next;
		Node(int data)
		{
			this.data = data;
			this.next = null;
		}
	}

	public static class LinkedList
	{
		Node head;
		Node tail;
		int size;

		void addFirst(int val)
		{
			Node new_node = new Node(val);
			if(size == 0)
			{
				head = tail = new_node;
				size++;
			}
			else
			{
				tail.next = new_node;
				tail = new_node;
				size++;
			}
		}

		void disp_all()
		{
			Node start_node = head;
			while(start_node != null)
			{
				System.out.print(start_node.data+" ");
				start_node = start_node.next;
			}
		}

	}
	public static void main(String []args)
	{
		LinkedList ll = new LinkedList();
		ll.addFirst(20);
		ll.addFirst(30);
		ll.addFirst(40);
		ll.disp_all();
	}
}