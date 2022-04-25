public class _222_1_binary_tree_constructor 
{
    public static class Node
    {
        int data;
        Node root;
        Node(int data,Node root)
        {
            this.data = data;
            this.root = root;
        }
    }

    public static class bst_constructor
    {
        int data;
        bst_constructor left;
        bst_constructor right;
        bst_constructor(int data,bst_constructor left,bst_constructor right)
        {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public static bst_constructor bst_converter(int arr[],int l,int r)
    {
        if(l > r)
        {
            return null;
        }
        int mid = (l+r)/2;
        int data = arr[mid];
        bst_constructor l_node = bst_converter(arr, l, mid-1);
        bst_constructor r_node = bst_converter(arr, mid+1, r);
        bst_constructor ans = new bst_constructor(data,l_node,r_node);
        return ans;
    }

    public static void disp_bst(bst_constructor root)
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
    

    public static void main(String args[])
    {
        int arr[] = {12,25,37,50,62,75,87};
        bst_constructor root = bst_converter(arr,0,arr.length-1);
        disp_bst(root);
    }    
}
