import java.util.*; 

public class _137_Add_last_a_linkedlist
{
	public static class Node
	{
		int data;
		Node next;
	}

	public static class LinkedList
	{
		Node head;
		Node tail;
		int size;

		void addLast(int val)
		{
			Node temp = new Node();
			temp.data = val;
			temp.next = null;
			if(size == 0)
			{
				head = tail = temp;
			}
			else
			{
				tail.next = temp;
				tail = temp;
			}
			size++;
		}

		public int size()
		{
			return size; 
		}

		public void display()
		{
			Node temp = head;
			while(temp != null)
			{
				System.out.print(temp.data+" ");
				temp = temp.next;
			}
			System.out.println();
		}

		public void removeFirst()
		{
			if(size == 0)
			{
				System.out.println("List is empty");
			}
			else if(size == 1)
			{
				head = null;
				tail = null;
				size = 0;
			}
			else
			{
				head = head.next;
				size--;	
			}
		}

		public int getFirst()
		{
			if(size == 0)
			{
				System.out.print("List is empty");
				return -1;
			}
			return head.data;
		}

		public int getTail()
		{
			if(size == 0)
			{
				System.out.print("List is empty");
				return -1;
			}
			return tail.data;
		}

		public int getAt(int idx)
		{
			if(size == 0)
			{
				System.out.print("List is empty");
				return -1;
			}
			if(idx < 0 || idx >= size)
			{
				System.out.print("Invalid Argument");
				return -1;
			}
			Node temp = head;
			for(int i=0;i<idx;i++)
			{
				temp = temp.next;
			}
			return temp.data;
		}

		public void addFirst(int val)
		{
			Node temp = new Node();
			temp.data = val;
			temp.next = head;
			head = temp;	
			if(size == 0)
			{
				tail = head;
			}
			size++;
		}

		public void addAt(int idx,int val)
		{
			if(idx < 0 || idx > size)
			{
				System.out.print("Invalid Argument");
				return;
			}
			else if(idx == 0)
			{
				addFirst(val);
			}
			else if(idx == size())
			{
				addLast(val);
			}
			else 
			{
				Node temp = head;
				for(int i=0;i<idx-1;i++)
				{
					temp = temp.next;
				}
				Node New = new Node();
				New.data = val;
				New.next = temp.next;
				temp.next = New;
				size++;
			}
		}

		public void removeLast()
		{
			if(size == 0)
			{
				System.out.print("List is empty");
			}
			else if(size == 1)
			{
				head = null;
				tail = null;
				size = 0;
			}
			else
			{
				Node temp = head;
				for(int i=0;i<size-2;i++)
				{
					temp = temp.next;
				}
				tail = temp;
				temp.next = null;
				size--;
			}
		}

		private Node getNodeAt(int idx)
		{
			Node temp = head;
			for(int i=0;i<idx;i++)
			{
				temp = temp.next;
			}
			return temp;
		}

		public void reverse_ll()
		{
			int l = 0;
			int r = size-1;
			while(l < r)
			{
				Node l_data = getNodeAt(l);
				Node r_data = getNodeAt(r);
				int temp = l_data.data;
				l_data.data = r_data.data;
				r_data.data = temp; 
				l++;
				r--;
			}
		}

		public void reverse_ll_pointer()
		{
			Node prev = null;
			Node curr = head;
			while(curr != null)
			{
				Node next = curr.next;
				curr.next = prev;
				prev = curr;
				curr = next;
			}
			Node temp = head;
			head = tail;
			tail = temp;
		}

		public void removeAt(int idx)
		{
			if(idx < 0 || idx >= size)
			{
				System.out.println("Invalid Argument");
			}
			else if(idx == 0)
			{
				removeFirst();
			}
			else if(idx == size-1)
			{
				removeLast();
			}
			else
			{
				Node temp = head;
				for(int i=0;i<idx-1;i++)
				{
					temp = temp.next;
				}
				temp.next = temp.next.next;
				size--;	
			}
		}
	
	}

	

	public static void main(String []args)
	{
		LinkedList ll = new LinkedList();

		ll.addLast(30);
		ll.addLast(40);
		ll.addLast(50);
		ll.display();
		ll.addFirst(0);
		ll.display();
		ll.removeFirst();
		ll.display();
		ll.removeLast();
		ll.display();
		ll.addAt(1,90);
		ll.display();
		ll.removeAt(1);
		ll.display();


		ll.addFirst(11);
		ll.addFirst(23);
		ll.addFirst(35);
		ll.addFirst(42);
		ll.display();
		ll.reverse_ll();
		ll.display();
		ll.reverse_ll_pointer();
		ll.display();
	}
}