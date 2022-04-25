import java.util.*; 

public class _192_Binary_tree_constructor_and_display
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
	}
}