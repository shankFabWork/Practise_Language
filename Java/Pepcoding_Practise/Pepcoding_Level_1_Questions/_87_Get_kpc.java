import java.lang.reflect.Array;
import java.util.*; 

public class _87_Get_kpc
{
    public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		ArrayList<String> ans = getKPC(str);
		System.out.println(ans);
		// System.out.println(ans.charAt(0).length());
    }

	
	// "345"
	// 3 45
	// 4 5
	// 5 ""
	// m n o
	// jkl

	static String str_arr[] = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    public static ArrayList<String> getKPC(String str) 
	{
		if(str.length() == 0)
		{
			ArrayList <String> al = new ArrayList<>();
			al.add("");
			return al;
		}
		char ch = str.charAt(0);
		String ros = str.substring(1);
		ArrayList <String> ral = getKPC(ros);
		ArrayList <String> nal = new ArrayList<>();
		String ch_code = str_arr[ch-48];
		for(int i=0;i<ch_code.length();i++)
		{
			char c = ch_code.charAt(i);
			for(String oc:ral)
			{
				nal.add(c+oc);
			}
		}
        return nal;
    }
}

