import java.util.*; 

public class _116_Duplicate_brackets
{
    public static class Node
    {
        int data;
        Node left;
        Node right;

        Node(int data,Node left,Node right)
        {
            this.data =data;
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

    public static void disp_bt(Node node) {
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

    public static void main(String args[])
    {
        Integer arr[] = {50, 25, 12, null, null, 37, 30, null, null, null, 75, 62, null, 70, null, null, 87, null, null};
        Stack <Pair> sta = new Stack<>();
        Node root = new Node(arr[0],null,null);
        Pair p = new Pair(root,1);
        sta.push(p);

        // for(int i=1;i<arr.length;i++)
        // {
        //     Pair pr = sta.peek();
        //     Node node = pr.node;
        //     int state = pr.state;
        //     if(state == 1)
        //     {
        //         if(arr[i] != null)
        //         {
        //             pr.state += 1;
        //             node.left = new Node(arr[i],null,null);
        //             sta.push(new Pair(node.left,1));    
        //         }
        //         pr.state += 1;
        //     }
        //     else if(state == 2 && arr[i] != null)
        //     {
        //         if(arr[i] != null)
        //         {
        //             node.right = new Node(arr[i],null,null);
        //             sta.push(new Pair(node.right,1));
        //         }
        //         pr.state += 1;    
        //     }
        //     else if(state == 3)
        //     {
        //         sta.pop();
        //     }
        // }

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