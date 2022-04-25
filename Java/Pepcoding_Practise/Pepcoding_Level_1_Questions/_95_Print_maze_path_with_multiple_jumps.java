import java.util.*; 

public class _95_Print_maze_path_with_multiple_jumps
{
    public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int m = scn.nextInt();
		ArrayList <String> al = new ArrayList <>();
		printMazePaths(1, 1, n, m, "",al);
		System.out.println(al);
    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static void printMazePaths(int sr, int sc, int dr, int dc, String psf,ArrayList <String> al) 
	{
		if(sr == dr && sc == dc)
		{
			// System.out.println(psf);
			al.add(psf);
			return;
		}
		for(int m = 1;m <= dc-sc;m++)
		{
			printMazePaths(sr, sc+m, dr, dc, psf+"h"+m,al);
		}
		for(int m = 1;m <= dr-sr;m++)
		{
			printMazePaths(sr+m, sc, dr, dc, psf+"v"+m,al);
		}
		for(int m = 1;m <= dc-sc && m <= dc-sc;m++)
		{
			printMazePaths(sr+m, sc+m, dr, dc, psf+"d"+m,al);
		}
    }


}