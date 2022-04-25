import java.util.*; 

public class _7_Digits_of_a_number
{
    public static int count_digit(int num)
    {
        int temp_num = num;
        int counter = 0;
        while(temp_num != 0)
        {
            counter++;
            temp_num = temp_num/10;
        }
        return counter;
    }
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();
        int no_of_digit = count_digit(n);
        int div = (int)Math.pow(10,no_of_digit-1);
        while(div != 0)
        // while(n != 0)
        {
            int first_digit = n/div;
            System.out.println(first_digit);
            n = n%div;
            div = div/10;
            // System.out.println(n);
        }
    }
}