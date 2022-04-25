import java.util.*; 

public class _7_Introduction_to_Arraylists_in_JAVA_Usage_and_Implementation_Arraylists_Tutorial
{
	public static void main(String []args)
	{
		// int arr[] = new int[5];
		// arr[0] = 20;
		// System.out.println(arr[0]);
		ArrayList <Integer> arr_list = new ArrayList<Integer>();
		System.out.println(arr_list+" "+arr_list.size());
		arr_list.add(10); 
		arr_list.add(20); 
		arr_list.add(30); 
		arr_list.add(40); 
		arr_list.add(50); 
		arr_list.add(1,1000);
		System.out.println(arr_list+" "+arr_list.size());
		System.out.println(arr_list.set(2,534));
		System.out.println(arr_list.get(2));
		System.out.println(arr_list+" "+arr_list.size());
		arr_list.remove(1);
		System.out.println(arr_list+" "+arr_list.size());

		// For Strings
		ArrayList <String> l2 = new ArrayList <String>();
		l2.add("shank");
		l2.add("gagan");
		l2.add("pankaj");
		System.out.println(l2+" "+l2.size());
		l2.remove(1);
		System.out.println(l2+" "+l2.size());
		l2.set(1,"horse");
		System.out.println(l2+" "+l2.size());
		l2.add(1,"rahul");
		System.out.println(l2+" "+l2.size());
		for(int i=0;i<l2.size();i++)
		{
			System.out.print(l2.get(i)+" ");
		}
		System.out.println();
		for(String data:l2)
		{
			System.out.println(data+" ");
		}
	}
}