import java.util.*; 

public class _6_Count_digits
{
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);
        int num = scn.nextInt();
        int temp_num = num;
        int counter = 0;
        while(temp_num != 0)
        {
            temp_num = temp_num/10;
            counter = counter + 1;
        }
        System.out.println(counter);
    }
}