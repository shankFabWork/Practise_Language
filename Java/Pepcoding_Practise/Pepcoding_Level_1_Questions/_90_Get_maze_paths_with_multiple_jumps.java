import java.util.*; 

public class _90_Get_maze_paths_with_multiple_jumps
{
    public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		int dr = scn.nextInt();
		int dc = scn.nextInt();
		ArrayList <String> al = getMazePaths(1, 1, dr, dc);
		System.out.print(al);
	}

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc) {
		if(sr == dr && sc == dc)
		{
			ArrayList <String> al = new ArrayList<>();
			al.add("");
			return al;
		}
		
		ArrayList <String> path = new ArrayList<>();
		for(int ms = 1;ms <= dc-sc;ms++)
		{
			ArrayList <String> hpath = getMazePaths(sr, sc+ms, dr, dc);
			for(String s:hpath)
			{
				path.add("h"+ms+s);
			}
		}
		for(int ms = 1;ms <= dr-sr;ms++)
		{
			ArrayList <String> vpath = getMazePaths(sr+ms, sc, dr, dc);
			for(String s:vpath)
			{
				path.add("v"+ms+s);
			}
		}
		for(int ms = 1;ms <= dc-sc && ms <= dr-sr ;ms++)
		{
			ArrayList <String> dpath = getMazePaths(sr+ms, sc+ms, dr, dc);
			for(String s:dpath)
			{
				path.add("d"+ms+s);
			}
		}
		return path;
    }

}