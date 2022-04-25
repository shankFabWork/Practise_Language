import java.util.*; 

public class _12_Introduction_To_Hashmap_Hashmap_and_Heaps_Data_Structure_and_Algorithms_in_JAVA
{
	public static void main(String []args)
	{
		// Population Distrbution
		HashMap <String,Integer> hm = new HashMap<>();
		hm.put("India",200);
		hm.put("Pakistan",2023);
		hm.put("Australia",204);
		hm.put("America",300);
		System.out.println(hm);
		hm.put("Nigeria",3223);
		System.out.println(hm);
		// Hashmap is out of order
		System.out.println(hm.get("India"));
		System.out.println(hm.get("Brazil"));
		System.out.println(hm.containsKey("India"));
		System.out.println(hm.containsKey("Brazil"));
		System.out.println(hm.keySet());
		Set <String> keys = hm.keySet();
		System.out.println(keys);

		// Interating HasMap Manually
		for(String key:hm.keySet())
		{
			System.out.println(key+" "+hm.get(key));
		}
	}
}