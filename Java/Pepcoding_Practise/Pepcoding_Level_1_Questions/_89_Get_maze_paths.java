import java.util.*; 

public class _89_Get_maze_paths
{
	// CRAM
    public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		int dr = scn.nextInt();
		int dc = scn.nextInt();
		ArrayList <String> al = getMazePaths(1,1, dr, dc);
		System.out.print(al);
	}

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc) {
		if(sc == dc && sr == dr)
		{
			ArrayList <String> al = new ArrayList<>();
			al.add("");
			return al; 
		}
		ArrayList <String> hpath = new ArrayList<>();
		ArrayList <String> vpath = new ArrayList<>();
		if(sc < dc)
		{
			hpath = getMazePaths(sr, sc+1, dr, dc);
		}
		if(sr < dr)
		{
			vpath = getMazePaths(sr+1, sc, dr, dc);
		}
		ArrayList <String> path = new ArrayList<>();
		for(String s:hpath)
		{
			path.add('h'+s);
		}
		for(String s:vpath)
		{
			path.add('v'+s);
		}
		return path;
    }

}