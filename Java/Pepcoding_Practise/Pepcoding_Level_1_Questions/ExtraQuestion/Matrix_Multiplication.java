// https://www.pepcoding.com/resources/online-java-foundation/2d-arrays/matrix-multiplication-official/ojquestion
// Status - Not Done

import java.util.*;

public class Matrix_Multiplication {
    public static void main(String []args)
    {
        Scanner scn = new Scanner(System.in);

        int r1 = scn.nextInt();
        int c1 = scn.nextInt();
        int arr_1[][] = new int[r1][c1];
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            {
                arr_1[i][j] = scn.nextInt();
            }    
        }

        int r2 = scn.nextInt();
        int c2 = scn.nextInt();
        int arr_2[][] = new int[r2][c2];
        for(int i=0;i<r2;i++)
        {
            for(int j=0;j<c2;j++)
            {
                arr_2[i][j] = scn.nextInt();
            }    
        }

        if(c1 != r2)
        {
            System.out.print("Invalid input");
            return;
        }
        else
        {
            int pro_matrix[][] = new int[r1][c2];
            for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c2;j++)
                {
                    for(int k=0;k<c1;k++)
                    {
                        pro_matrix[i][j] += arr_1[i][k] * arr_2[k][j];
                    }
                }    
            }    
            for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c2;j++)
                {
                    System.out.print(pro_matrix[i][j]+" ");
                }
                System.out.println();
            }
            
        }
    }
    
}
