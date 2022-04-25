import java.util.*; 

public class _86_Get_subsequence
{

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        ArrayList <String> al = gss(str);
		String ns = "";
		for(int i=0;i<str.length();i++)
		{
			ns += " ";
		}
		// System.out.println(ns+"a");
		for(int i=0;i<al.size();i++)
		{
			if(al.get(i).equals(ns))
			{
				// System.out.println(al.get(i)+"a");
				al.set(i,"");
			}
		}
        System.out.print(al);
    }

    public static ArrayList<String> gss(String str) {
        if(str.length() == 0)
        {
            ArrayList <String> al = new ArrayList <String>();
            al.add("");
            return al;
        }
        char ch = str.charAt(0);
        String sub_string = str.substring(1);
        ArrayList <String> temp_al = gss(sub_string);
        ArrayList <String> real_al = new ArrayList<String>();
		for(String s:temp_al)
        {
            real_al.add(""+s);
        }
        for(String s:temp_al)
        {
			real_al.add(ch+s);
		}
        return real_al;
    }
}

// [, c, b, bc, a, ac, ab, abc]
// [, c, b, bc, a, ac, ab, abc]