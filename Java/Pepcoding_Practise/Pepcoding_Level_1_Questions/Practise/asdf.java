import java.util.*;

public class asdf 
{
    public static void addEdge(ArrayList<ArrayList<Integer>> al,int u,int v)
    {
        al.get(u).add(v);
        al.get(v).add(u);
    }

    public static void main(String args[])
    {
        int n = 3;
        ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>(n+1);
        for(int i=0;i<=n;i++)
        {
            al.add(new ArrayList<Integer>());
        }
        addEdge(al, 0, 1);
        addEdge(al, 0, 2);
        addEdge(al, 2, 1);
        addEdge(al, 3, 1);
        for(int i=0;i<al.size();i++)
        {
            for(int j=0;j<al.get(i).size();j++)
            {
                System.out.print(al.get(i).get(j)+" ");
            }
            System.out.println();
        }
    }
}
