import java.util.*; 

public class _193_Size_sum_max_and_height_of_binarytree
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
		int sz = (l+r)+1;
		return sz;
	}

	public static int sum_of_bt(Node root)
	{
		if(root == null)
		{
			return 0;
		}
		int l = size_of_bt(root.left);
		int r = size_of_bt(root.right);
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

        disp_bt(root);
		System.out.println(size_of_bt(root));
		System.out.println(sum_of_bt(root));
		System.out.println(max_of_bt(root));
		System.out.println(height_of_bt(root));
	}
}