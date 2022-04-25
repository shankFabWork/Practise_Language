import java.util.*; 

public class _97_Print_encodings
{
    public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		printEncodings(str,"");
    }

    public static void printEncodings(String str,String asf) {
		if(str.length() == 0)
		{
			System.out.println(asf);
			return;
		}
		else if(str.length() == 1)
		{
			char ch = str.charAt(0);
			if(ch == '0')
			{
				return;
			}
			else
			{
				char code = (char)((ch-'0')+'a'-1);
				System.out.println(asf+code);
			}
		}
		else
		{
			// First Character
			char ch = str.charAt(0);
			String ros1 = str.substring(1);
			if(ch == '0')
			{
				return;
			}
			else
			{
				char code = (char)((ch-'0')+'a'-1);
				printEncodings(ros1, asf+code);
			}

			// Second Character
			String ch12 = str.substring(0,2);
			String ros2 = str.substring(2);
			int ch12v = Integer.parseInt(ch12);
			if(ch12v <= 26)
			{
				char code = (char)(ch12v+'a'-1);
				printEncodings(ros2, asf+code);
			}
		}
    }

}