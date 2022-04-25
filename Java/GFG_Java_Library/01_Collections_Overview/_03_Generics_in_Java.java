// Generics in Java 
// 1) Write Once ,use for any non-primitive datatype
// 2) Type safety

import java.util.*;

// Generic Class
class Pair<A,B>
{
    A name;
    B age;

    Pair(A a,B b)
    {
        name = a;
        age = b;
    }
}

class MyGeneric <T>
{
    static int counter;
    MyGeneric()
    {
        counter++;
    }
}

public class _03_Generics_in_Java
{
    // Generic Collection
    public static <T> int FindArrayElem(T arr[],T x)
    {
        int counter = 0;
        for(T data:arr)
        {
            if(data == x)
            {
                break;
            }
            counter++;
        }
        return counter;
    }
    public static void main(String[] args)
    {
        // System.out.println();
        Pair <String,Integer> p = new Pair <String,Integer>("shank",20);
        System.out.println(p.name+" "+p.age);
        // ArrayList <Integer> al = new ArrayList<Integer>();
        // al.add(10);
        Integer arr[] = {10,20,30};
        int find_elem = 10;
        System.out.println(FindArrayElem(arr,find_elem));

        MyGeneric<Integer> mg1 = new MyGeneric<Integer>();
        MyGeneric<Integer> mg2 = new MyGeneric<Integer>();
        System.out.println(MyGeneric.counter);
    }
}
