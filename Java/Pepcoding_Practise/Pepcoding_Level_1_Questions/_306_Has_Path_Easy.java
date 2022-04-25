import java.util.*; 

public class _306_Has_Path_Easy
{


	public static void addEdge(ArrayList<ArrayList<Integer>> al,int a,int b)
	{
		al.get(a).add(b);
		al.get(b).add(a);
	}

	public static void main(String []args)
	{
		int n = 10;
		ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>(n+1);

		for(int i=0;i<=n;i++)
		{
			al.add(new ArrayList<Integer>());
		}
 
        addEdge(al, 0, 3);
        addEdge(al, 3, 4);
        addEdge(al, 4, 6);
        addEdge(al, 6, 8);

        addEdge(al, 2, 9);

        addEdge(al, 5, 7);
        addEdge(al, 7, 10);

		int visited[] = new int[n+1];
		Queue <Integer> que = new ArrayDeque<Integer>();
		for(int i=0;i<al.size();i++)
		{
			// System.out.print(i+" -> ");
			if(visited[i] == 0 && al.get(i).size() != 0)
			{
				int s = i;
				visited[s] = 1;
				que.offer(s);
				while(que.size() > 0)
				{
					int elem = que.peek();
					que.poll();
					System.out.print(elem+" ");
					for(int val:al.get(elem))
					{
						if(visited[val] == 0)
						{
							visited[val] = 1;
							que.offer(val);
 						}
					}
				}	
			}
			System.out.println();
		}

		// for(int i=0;i<al.size();i++)
		// {
		// 	System.out.print(i+"->");
		// 	for(int j=0;j<al.get(i).size();j++)
		// 	{	
		// 		if(al.get(i).contains(j) == true)
		// 		{
		// 			System.out.print(al.get(i).get(j)+" ");
		// 		}
		// 	}
		// 	System.out.println();
		// }


	}
}