import java.util.*; 

public class _196_Find_and_node_to_root_path_in_binary_tree
{
	public static class Node
	{
		int data;
		Node left;
		Node right;
		Node(int data,Node left,Node right)
		{
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}

	public static class Pair
	{
		Node node;
		int state;
		Pair(Node node,int state)
		{
			this.node = node;
			this.state = state;
		}
	}

	public static int size_of_bt(Node root)
	{
		if(root == null)
		{
			return 0;
		}
		int l = size_of_bt(root.left);
		int r = size_of_bt(root.right);
		int sz = l+r+1;
		return sz;
	}

	public static int sum_of_bt(Node root)
	{
		if(root == null)
		{
			return 0;
		}
		int l = sum_of_bt(root.left);
		int r = sum_of_bt(root.right);
		int sz = l+r+root.data;
		return sz;
	}

	public static int max_of_bt(Node root)
	{
		if(root == null)
		{
			return Integer.MIN_VALUE;
		}
		int l = max_of_bt(root.left);
		int r = max_of_bt(root.right);
		return Math.max(root.data,Math.max(l,r));
	}

	public static int height_of_bt(Node root)
	{
		if(root == null)
		{
			// for finding height on nodes
			// return 0;
			// for finding height on edge
			return -1;
		}
		int l = height_of_bt(root.left);
		int r = height_of_bt(root.right);
		return Math.max(l,r)+1;
	}
	
	public static void disp_bt(Node node) 
	{
        if (node == null) {
          return;
        }
    
        String str = " <- " + node.data + " -> ";
    
        String left = (node.left == null) ? "." :  "" + node.left.data;
        String right = (node.right == null) ? "." : "" + node.right.data;
    
        str = left + str + right;
    
        System.out.println(str);
    
        disp_bt(node.left);
        disp_bt(node.right);
      }

	public static void Iterative_pre_post_and_in_of_bt(Node root)
	{
		Stack <Pair> sta = new Stack<>();
		sta.push(new Pair(root,1));
		String pre_str = "";
		String in_str = "";
		String post_str = "";
		while(sta.size() != 0)
		{
			Pair pair_obj = sta.peek();
			int data = pair_obj.node.data;
			int state = pair_obj.state;
			if(state == 1)
			{
				pair_obj.state += 1;
				pre_str += data+" ";

				Node l = pair_obj.node.left;
				if(l != null)
				{
					sta.push(new Pair(l,1));
				}
			}
			else if(state == 2)
			{
				pair_obj.state += 1;
				in_str += data+" ";

				Node r = pair_obj.node.right;
				if(r != null)
				{
					sta.push(new Pair(r,1));
				}
			}
			else if(state == 3)
			{
				post_str += data+" ";
				sta.pop();
			}
		}
		System.out.println(pre_str);
		System.out.println(in_str);
		System.out.println(post_str);
	}

	public static boolean find(Node root,int key)
	{ 
		if(root == null)
		{
			return false;
		}
		if(root.data == key)
		{
			return true;
		}
		boolean l_bool = find(root.left, key);
		if(l_bool == true)
		{
			return true;
		}
		boolean r_bool = find(root.right, key);
		if(r_bool == true)
		{
			return true;
		}
		return false;
	}

	public static ArrayList <Integer> find_path_from_node_to_root(Node root,int key)
	{
		if(root == null)
		{
			return new ArrayList<>();
		}
		if(root.data == key)
		{
			ArrayList <Integer> list = new ArrayList<>();
			list.add(root.data);
			return list;
		}
		ArrayList <Integer> l_list = find_path_from_node_to_root(root.left,key);
		if(l_list.size() > 0)
		{
			l_list.add(root.data);
			return l_list;
		}
		ArrayList <Integer> r_list = find_path_from_node_to_root(root.right,key);
		if(r_list.size() > 0)
		{
			r_list.add(root.data);
			return r_list;
		}
		return new ArrayList<>();
	}


	public static void main(String []args)
	{
		Integer arr[] = {50, 25, 12, null, null, 37, 30, null, null, null, 75, 62, null, 70, null, null, 87, null, null};
        Stack <Pair> sta = new Stack<>();
        Node root = new Node(arr[0],null,null);
        Pair p = new Pair(root,1);
        sta.push(p);

        int idx = 1;
        while(sta.size() != 0)
        {
            Pair pair = sta.peek();
            if(pair.state == 1)
            {
                if(arr[idx] != null)
                {
                    Node new_node = new Node(arr[idx],null,null);
                    pair.node.left = new_node;
                    sta.push(new Pair(new_node,1));    
                }
                pair.state += 1;
                idx++;
            }
            else if(pair.state == 2)
            {
                if(arr[idx] != null)
                {
                    Node new_node = new Node(arr[idx],null,null);
                    pair.node.right = new_node;
                    sta.push(new Pair(new_node,1));    
                }
                pair.state += 1;
                idx++;
            }
            else if(pair.state == 3)
            {
                sta.pop();
            }
        }
		System.out.println(sum_of_bt(root));

		// ArrayList <Integer> al = new ArrayList<>();
		int key = 37;
		System.out.println(find(root,key));
		System.out.print(find_path_from_node_to_root(root,key));
	}
}