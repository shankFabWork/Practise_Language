public class String_to_Integer {
    public static void main(String args[])
    {
        // String str = "122";
        String str = "sdfs  122";
        // String str = "-122";
        // String str = "   -122";
        // String str = "   -122 dsdf";
        int i=0;
        while(i<str.length() && str.charAt(i) == ' ')
        {
                i++;
        }
        boolean pos = true;
        if(i<str.length() && str.charAt(i) == '-')
        {
            pos = false;
            i++;
        }
        else if(i<str.length() && str.charAt(i) == '+')
        {
            i++;
        }

        int num = 0;
        while(i<str.length() && (str.charAt(i) >= '0' && str.charAt(i) <= '9') )
        {
            int digit = str.charAt(i)-'0';
            if((Integer.MAX_VALUE-digit)/10 < num)
            {
                if(pos == true)
                {
                    System.out.println(Integer.MAX_VALUE);                
                }    
                else
                {
                    System.out.println(Integer.MIN_VALUE);
                }                
            }
            num = num * 10 + digit;
            i++;
        }

        if(num == 0)
        {
            System.out.println(0);
        }
        else
        {
            if(pos == true)
            {
                System.out.println(num);
            }
            else
            {
                System.out.println(-1*num);
            }
        }
    }
}
