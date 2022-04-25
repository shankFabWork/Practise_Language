public class Int_to_roman {
    public static void main(String args[])
    {
        int val = 1994;
        // I             1
        // V             5
        // X             10
        // L             50
        // C             100
        // D             500
        // M             1000
        String symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        StringBuilder ans_str = new StringBuilder();
        int n = value.length;
        for(int i=0;i<n;i++)
        {
            while(value[i] <= val)
            {
                ans_str.append(symbol[i]);
                val = val - value[i];
            }
        }

        System.out.print(ans_str.toString());
    }
}
