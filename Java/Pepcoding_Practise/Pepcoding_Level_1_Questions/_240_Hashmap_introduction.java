import java.util.*; 

public class _240_Hashmap_introduction
{
	public static void main(String []args)
	{
		HashMap <String ,Integer> hm = new HashMap <String ,Integer> ();
		hm.put("India",100);
		hm.put("China",200);
		hm.put("America",300);
		// System.out.print(hm.get("India"));
		// Update value with put
		hm.put("India",4300);
		// System.out.print(hm.get("India"));
		// System.out.print(hm.get("Nigeria"));
		// System.out.print(hm.containsKey("Nigeria"));

		// Set <String> s = hm.keySet();
		// System.out.print(s);
		for(String s:hm.keySet())
		{
			int val = hm.get(s);
			System.out.println(s+" "+val);
		}
	}	
}