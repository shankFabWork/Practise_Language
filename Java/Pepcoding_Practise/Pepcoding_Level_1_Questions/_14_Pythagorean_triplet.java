import java.util.*; 

public class _14_Pythagorean_triplet
{
    public static boolean pytha(int a,int b,int c)
    {
        if(a*a+b*b == c*c) return true;
        else if(a*a+c*c == b*b) return true;
        else if(c*c+b*b == a*a) return true;
        else return false;
    }
    
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int a = scn.nextInt();
        int b = scn.nextInt();
        int c = scn.nextInt();
        System.out.print(pytha(a,b,c));
    }
}