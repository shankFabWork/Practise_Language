import java.util.*; 

public class _92_Print_kpc
{
    public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		printKPC(str, "");
    }
	static String str_arr[] = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    public static void printKPC(String str, String asf) {
		if(str.length() == 0)
		{
			System.out.println(asf);
			return;
		}
		char ch = str.charAt(0);
		String new_str = str.substring(1);
		String code_data = str_arr[ch-'0'];
		for(int i=0;i<code_data.length();i++)
		{
			char code_ch = code_data.charAt(i);
			printKPC(new_str, asf+code_ch);
		}
	}
}