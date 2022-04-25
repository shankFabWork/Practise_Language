import java.util.*; 

public class _225_Remove_node_in_bst
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
		else if(root.data < d1 && root.data < d2)
		{
			return LCA_BST(root.right, d1, d2);
		}
		return root.data;
	}

    public static void main(String args[])
    {
        int arr[] = {12,25,37,50,62,75,87};
        Node root = bst_converter(arr,0,arr.length-1);
        // disp_bst(root);
		// System.out.println(find_elem(root,62));
		// System.out.println(max_elem_in_bst(root));
		// System.out.println(min_elem_in_bst(root));
		// System.out.println(sum_bst(root));
		// root = add_elem(root,911);
		System.out.println("----------------------");
        disp_bst(root);
		System.out.println("----------------------");
		root = remove_node_bst(root,87);
        disp_bst(root);
		System.out.println("----------------------");
		// Replace_with_sum_of_larger(root);
        // disp_bst(root);
		// System.out.println("----------------------");
		// int ans = LCA_BST(root,62,87);
		// System.out.print(ans);
	}    
}