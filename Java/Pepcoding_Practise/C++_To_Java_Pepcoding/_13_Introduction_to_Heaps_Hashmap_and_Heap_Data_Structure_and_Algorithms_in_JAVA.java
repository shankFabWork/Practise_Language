import java.util.*; 

public class _13_Introduction_to_Heaps_Hashmap_and_Heap_Data_Structure_and_Algorithms_in_JAVA
{
	public static void main(String []args)
	{
		PriorityQueue <Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
		int arr[] = {22,99,3,11,88,4,1};

		// O(n.log(n))
		for(int data:arr)
		{
			pq.add(data);
		}

		// O(n.log(n))
		while(pq.size() > 0)
		{
			System.out.println(pq.peek());
			pq.remove();
		}
	}
}