import java.util.*; 
// top left down right
public class _99_Flood_fill
{
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = scn.nextInt();
            }
        }
		boolean barr[][] = new boolean[n][m];
        floodfill(arr, 0, 0, "",barr);
    }
    
    // asf -> answer so far
    public static void floodfill(int[][] maze, int sr, int sc, String asf,boolean barr[][]) {
		if(sr < 0 || sc < 0 || sr == maze.length || sc == maze[0].length || maze[sr][sc] == 1 ||
		 barr[sr][sc] == true)
		{
			return;
		}
		if(sr == maze.length-1 && sc == maze[0].length-1)
		{
			System.out.println(asf);
			return;
		}
		barr[sr][sc] = true;
		floodfill(maze, sr-1, sc, asf+'t',barr);
		floodfill(maze, sr, sc-1, asf+'l',barr);
		floodfill(maze, sr+1, sc, asf+'d',barr);
		floodfill(maze, sr, sc+1, asf+'r',barr);
		barr[sr][sc] = false;
    }
}