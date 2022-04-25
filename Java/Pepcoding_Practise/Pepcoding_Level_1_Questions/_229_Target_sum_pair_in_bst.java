import java.util.*; 

public class _229_Target_sum_pair_in_bst
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
		int state;
		Node node;
		Pair(Node node,int state)
		{
			this.state = state;
			this.node = node;
		}
	}

    public static Node bst_converter(int arr[],int l,int r)
    {
        if(l > r)
        {
            return null;
        }
        int mid = (l+r)/2;
        int data = arr[mid];
        Node l_node = bst_converter(arr, l, mid-1);
        Node r_node = bst_converter(arr, mid+1, r);
        Node ans = new Node(data,l_node,r_node);
        return ans;
    }

    public static void disp_bst(Node root)
    {
        if(root == null)
        {
            return;
        }
        String str = "";
        str += (root.left == null) ?".":root.left.data+"";
        str += "<"+root.data+">";
        str += (root.right == null) ?".":root.right.data+"";
        System.out.println(str);
        if(root != null)
        {
            disp_bst(root.left);
            disp_bst(root.right);    
        }
    }

	public static int max_elem_in_bst(Node root)
	{
		if(root.right != null)
		{
			return max_elem_in_bst(root.right);
		}
		return root.data;
	}

	
	public static int min_elem_in_bst(Node root)
	{
		if(root.left != null)
		{
			return min_elem_in_bst(root.left);
		}
		return root.data;
	}

	public static boolean find_elem(Node root,int key)
	{
		if(root == null)
		{
			return false;
		}
		if(root.data == key)
		{
			return true;
		}
		else if(root.data > key)
		{
			return find_elem(root.left, key);
		}
		else if(root.data < key)
		{
			return find_elem(root.right, key);
		}
		return false;
	}

	public static int sum_bst(Node root)
	{
		if(root == null)
		{
			return 0;
		}
		int l_ans = sum_bst(root.left);
		int r_ans = sum_bst(root.right);
		return root.data + l_ans + r_ans;
	}

	public static Node add_elem(Node root,int data)
	{
		if(root == null)
		{
			return new Node(data,null,null);
		}
		if(data < root.data)
		{
			root.left = add_elem(root.left, data);
		}
		else if(data > root.data)
		{
			root.right = add_elem(root.right, data);
		}
		return root;
	}

	public static int lmax(Node node)
	{
		if(node.right != null)
		{
			return lmax(node.right);
		}
		else
		{
			return node.data;
		}
	}

	public static Node remove_node_bst(Node root,int key)
	{
		if(root == null)
		{
			return null;
		}
		if(root.data > key)
		{
			root.left = remove_node_bst(root.left, key);
		}
		else if(root.data < key)
		{
			root.right = remove_node_bst(root.right, key);
		}
		else 
		{
			if(root.left != null && root.right != null)
			{
				int d = lmax(root.left);
				root.data = d;
				root.left = remove_node_bst(root.left,d);
				return root;
			}		
			else if(root.left != null)	
			{
				return root.left;
			}
			else if(root.right != null)
			{
				return root.right;
			}	
			else
			{
				return null;
			}
		}
		return root;
	}
    static int sum = 0;
	public static void Replace_with_sum_of_larger(Node root)
	{
		if(root == null)
		{
			return;
		}
		Replace_with_sum_of_larger(root.left);
		int r_data = root.data;
		root.data = sum;
		sum += r_data;
		Replace_with_sum_of_larger(root.right);
	}

	public static int LCA_BST(Node root,int d1,int d2)
	{
		if(root.data > d1 && root.data > d2)
		{
			return LCA_BST(root.left, d1, d2);
		}
		else if(root.data > d1 && root.data > d2)
		{
			return LCA_BST(root.left, d1, d2);
		}
		return root.data;
	}

	public static void print_in_range_of_bst(Node root,int r1,int r2)
	{
		if(root == null)
		{
			return;
		}
		if(root.data > r1 && root.data < r2)
		{
			print_in_range_of_bst(root.left,r1,r2);
			System.out.print(root.data+" ");
			print_in_range_of_bst(root.right,r1,r2);
		}
		else if(root.data < r1 && root.data < r2)
		{
			print_in_range_of_bst(root.right,r1,r2);
		}		
		else if(root.data > r2 && root.data > r1)
		{
			print_in_range_of_bst(root.left,r1,r2);
		}
	}

	public static boolean find_val(Node root,int find_key,int curr)
	{
		if(root == null)
		{
			return false;
		}
		if(root.data == find_key && root.data != curr)
		{
			return true;
		}
		else if(root.data < find_key)
		{
			return find_val(root.right,find_key,curr);
		}
		else if(root.data > find_key)
		{
			return find_val(root.left,find_key,curr);
		}
		return false;
	}

	public static void target_sum_pair_in_bst_1(Node root,Node node,int key,HashMap <Integer,Integer> hm)
	{
		if(node == null)
		{
			return;
		}
		target_sum_pair_in_bst_1(root, node.left, key,hm);
		int curr = node.data;
		if(curr < key)
		{
			int find_key = key - curr;
			if(find_val(root,find_key,curr) == true)
			{
				if(curr < find_key)
				{
					hm.put(curr,find_key);
					// System.out.println(curr+" "+find_key);
				}
				else
				{
					hm.put(find_key,curr);
					// System.out.println(find_key+" "+curr);
				}
			}
		}
		target_sum_pair_in_bst_1(root, node.right, key,hm);
	}

	// public static void target_sum_pair_in_bst_2(Node root,Node node,int key)
	public static void target_sum_pair_in_bst_2(int arr[],int key)
	{
		int l = 0;
		int r = arr.length-1;
		while(l < r)
		{
			if(arr[l]+arr[r] == key)
			{
				System.out.println(arr[l]+" "+arr[r]);
				l++;
				r--;
			}
			if(arr[l]+arr[r] < key)
			{
				l = l + 1;
			}
			else if(arr[l]+arr[r] > key)
			{
				r = r-1;
			}
		}	
	}

	public static Node inorder_value(Stack <Pair> sta)
	{
		while(sta.size() > 0)
		{
			Pair sta_pair = sta.peek();
			int state = sta_pair.state;
			Node node = sta_pair.node;
			if(state == 1)
			{
				if(node.left != null)
				{
					sta.push(new Pair(node.left,1));
				}
				sta_pair.state += 1;
			}
			else if(state == 2)
			{
				if(node.right != null)
				{
					sta.push(new Pair(node.right,1));
				}
				sta_pair.state += 1;
				return node;	
			}
			else if(state == 3)
			{
				sta.pop();
			}
		}
		return null;
	}

	public static Node rev_inorder_value(Stack <Pair> sta)
	{
		while(sta.size() > 0)
		{
			Pair sta_pair = sta.peek();
			int state = sta_pair.state;
			Node node = sta_pair.node;
			if(state == 1)
			{
				if(node.right != null)
				{
					sta.push(new Pair(node.right,1));
				}
				sta_pair.state += 1;
			}
			else if(state == 2)
			{
				if(node.left != null)
				{
					sta.push(new Pair(node.left,1));
				}
				sta_pair.state += 1;
				return node;	
			}  
			else if(state == 3)
			{
				sta.pop();
			}
		}
		return null;	
	}

	public static void target_sum_pair_in_bst_3(Node root,int key)
	{
		Stack <Pair> ls = new Stack<>();
		Stack <Pair> rs = new Stack<>();
		ls.push(new Pair(root,1));
		rs.push(new Pair(root,1));
		Node in_first = inorder_value(ls);
		Node rev_in_first = rev_inorder_value(rs);
		while(in_first.data < rev_in_first.data)
		{
			if(in_first.data+rev_in_first.data == key)
			{
				System.out.println(in_first.data+" "+rev_in_first.data);
				in_first = inorder_value(ls);
				rev_in_first = rev_inorder_value(rs);
			}
			else if(in_first.data+rev_in_first.data > key)
			{
				rev_in_first = rev_inorder_value(rs);
			}
			else if(in_first.data+rev_in_first.data < key)
			{
				in_first = inorder_value(ls);
			}
		}	
	}

	public static void print_preorder_inorder_postorder(Node root)
	{
		Stack <Pair> sta = new Stack<>();
		sta.push(new Pair(root,1));
		String pre = "";
		String in = "";
		String post = "";
		while(sta.size() != 0)
		{
			Pair sta_obj = sta.peek();
			int state = sta_obj.state;
			Node node = sta_obj.node;
			if(state == 1)
			{
				if(node.left != null)
				{
					sta.push(new Pair(node.left,1));
				}
				pre += node.data+" ";
				sta_obj.state += 1;
			}
			else if(state == 2)
			{
				if(node.right != null)
				{
					sta.push(new Pair(node.right,1));
				}
				in += node.data+" ";
				sta_obj.state += 1;
			}
			else
			{
				post += node.data+" ";
				sta.pop();
			}
		}
		System.out.println(pre);
		System.out.println(in);
		System.out.println(post);
	}

    public static void main(String args[])
    {
		// for bst array should be sorted
        int arr[] = {12,25,37,40,50,60,62,75,87};
        Node root = bst_converter(arr,0,arr.length-1);
        // disp_bst(root);
		// System.out.println(find_elem(root,62));
		// System.out.println(max_elem_in_bst(root));
		// System.out.println(min_elem_in_bst(root));
		// System.out.println(sum_bst(root));
		// root = add_elem(root,911);
		// System.out.println("----------------------");
        // disp_bst(root);
		// System.out.println("----------------------");
		// root = remove_node_bst(root,911);
        // disp_bst(root);
		// System.out.println("----------------------");
		// Replace_with_sum_of_larger(root);
        // disp_bst(root);
		// System.out.println("----------------------");
		// int ans = LCA_BST(root,62,87);
		// System.out.print(ans);
		// print_in_range_of_bst(root,27,72);

		print_preorder_inorder_postorder(root);

		System.out.println();
		// 1st Way
		int key = 100;
		HashMap <Integer,Integer> hm = new HashMap<>();
		target_sum_pair_in_bst_1(root,root,key,hm);
		// TC - O(n.log(n))
		// SC - O(log(n))
		// log(n) => height

		// Set <Integer> s = hm.keySet();
		// for(int elem:s)
		// {
		// 	System.out.println(elem+" "+hm.get(elem));
		// }
		ArrayList <Integer> al = new ArrayList<>(hm.keySet());
		Collections.sort(al);
		for(int elem:al)
		{
			System.out.println(elem+" "+hm.get(elem));
		}

		System.out.println();

		// 2st Way
		target_sum_pair_in_bst_2(arr,key);
		// TC - O(n)
		// SC - O(n)

		System.out.println();

		// 3st Way
		target_sum_pair_in_bst_3(root,key);
		// TC - O(log(n))
		// SC - O(n)
	}    
}