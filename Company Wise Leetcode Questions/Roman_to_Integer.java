import java.util.*;
// import

public class Roman_to_Integer
{
    public static void main(String args[])
    {
        String str = "III";
        // String str = "LVIII";
        // String str = "MCMXCIV";
        String symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int n = symbol.length;
        HashMap <String,Integer> hm = new HashMap<>();
        for(int i=0;i<n;i++)
        {
            hm.put(symbol[i],value[i]);
        }
        int str_len = str.length();
        char lastCh = str.charAt(str_len-1);
        int ans = hm.get(lastCh+"");

        for(int i=str_len-1;i>=1;i--)
        {
            char ch_i = str.charAt(i);   
            char ch_i_1 = str.charAt(i-1);   
            int val_i = hm.get(ch_i+"");
            int val_i_1 = hm.get(ch_i_1+"");
            if(val_i > val_i_1)
            {
                ans = ans - val_i_1;
            }
            else
            {
                ans = ans + val_i_1;
            }
        }
        System.out.print(ans);


    }
}