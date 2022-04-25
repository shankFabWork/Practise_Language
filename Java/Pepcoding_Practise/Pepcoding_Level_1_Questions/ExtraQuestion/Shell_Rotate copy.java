import java.util.*;

public class Shell_Rotate 
{
    public static int[] fill_oned_from_shell(int [][]arr,int s)
    {
        int r = arr.length;
        int c = arr[0].length;

        int minr = s-1;
        int maxr = r-s;
        int minc = s-1;
        int maxc = c-s;
        int sz = 2*(maxr-minr+maxc-minc);

        int one_d[] = new int[sz];
        int idx = 0;
        for(int i=minr,j=minc;i<=maxr;i++)
        {
            one_d[idx] = arr[i][j];
            idx++;
        }

        for(int i=maxr,j=minc+1;j<=maxc;j++)
        {
            one_d[idx] = arr[i][j];
            idx++;
        }

        for(int i=maxr-1,j=maxc;i>=minr;i--)
        {
            one_d[idx] = arr[i][j];
            idx++;
        }

        for(int i=minr,j=maxc-1;j>=minc+1;j--)
        {
            one_d[idx] = arr[i][j];
            idx++;
        }
        return one_d;
    }

    public static void reverse_arr(int one_d[],int s,int e)
    {
        while(s <= e)
        {
            int temp = one_d[s];
            one_d[s] = one_d[e];
            one_d[e] = temp;
            s++;
            e--;
        }
    }

    public static void rotate_arr(int one_d[],int k)
    {
        int n = one_d.length;
        if(k < 0)
        {
            k = (k%n)+n;
        }
        else
        {
            k = (k%n);
        }
        reverse_arr(one_d,0,n-k-1);
        reverse_arr(one_d,n-k,n-1);
        reverse_arr(one_d,0,n-1);
    }       

    public static void fill_shell_from_oned(int arr[][],int one_d[],int s)
    {
        int r = arr.length;
        int c = arr[0].length;

        int minr = s-1;
        int maxr = r-s;
        int minc = s-1;
        int maxc = c-s;

        int idx = 0;
        for(int i=minr,j=minc;i<=maxr;i++)
        {
            arr[i][j] = one_d[idx++];
        }

        for(int i=maxr,j=minc+1;j<=maxc;j++)
        {
            arr[i][j] = one_d[idx++];
        }

        for(int i=maxr-1,j=maxc;i>=minr;i--)
        {
            arr[i][j] = one_d[idx++];
        }

        for(int i=minr,j=maxc-1;j>=minc+1;j--)
        {
            arr[i][j] = one_d[idx++];
        }
    }

    public static void print_arr(int arr[][])
    {
        int row = arr.length;
        int column = arr[0].length;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                System.out.print(arr[i][j]+" ");
            }    
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);

        int row = scn.nextInt();
        int column = scn.nextInt();
        int arr[][] = new int[row][column];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                arr[i][j] = scn.nextInt();
            }    
        }
        int s = scn.nextInt();
        int r = scn.nextInt();
            
        int one_d[] = fill_oned_from_shell(arr,s);
        rotate_arr(one_d, r);
        fill_shell_from_oned(arr,one_d,s);
        print_arr(arr);
    }
}

// 4
// 4
// 1 2 3 4
// 5 6 7 8 
// 9 10 11 12
// 13 14 15 16
// 1
// 1