import java.util.*; 

public class _10_Inverse_a_number
{
    public static int inverse_of_number(int num)
    {
        int temp_num = num;
        int inv_num = 0;
        int index_no = 1;
        while(temp_num != 0)
        {
            int last_dig = temp_num%10;
            inv_num += index_no*(int)Math.pow(10,last_dig-1);
            index_no += 1;
            temp_num = temp_num/10;
        }
        return inv_num;
    }
    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        int num = scn.nextInt();
        int data = inverse_of_number(num);
        System.out.println(data);
    } 
}