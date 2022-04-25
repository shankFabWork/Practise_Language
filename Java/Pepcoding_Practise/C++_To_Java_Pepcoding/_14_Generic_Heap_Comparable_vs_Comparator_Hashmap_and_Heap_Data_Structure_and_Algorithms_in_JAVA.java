import java.util.*; 

public class _14_Generic_Heap_Comparable_vs_Comparator_Hashmap_and_Heap_Data_Structure_and_Algorithms_in_JAVA
{
	static class Student
	// static class Student implements Comparable<Student>
	{
		int rno;
		int ht;
		int wt;

		Student(int rno,int ht,int wt)
		{
			this.rno = rno;
			this.ht = ht;
			this.wt = wt;
		}

		// public int compareTo(Student c)
		// {
		// 	return this.rno - c.rno;
		// }
	}
	
	public static void ShowString(PriorityQueue <Student> pq)
	{
		while(pq.size() > 0)
		{
			Student s = pq.peek();
			System.out.println(s.rno+" "+s.wt+" "+s.ht);
			pq.remove();
		}
	}

	static class StudentWtComparator implements Comparator<Student>
	{
		public int compare(Student s1,Student s2)
		{
			return s1.wt - s2.wt;
		}
	}

	static class StudentHtComparator implements Comparator<Student>
	{
		public int compare(Student s1,Student s2)
		{
			return s1.ht - s2.ht;
		}
	}

	static class StudentRnoComparator implements Comparator<Student>
	{
		public int compare(Student s1,Student s2)
		{
			return s1.ht - s2.ht;
		}
	}
	public static void main(String []args)
	{
		PriorityQueue <Student> pq = new PriorityQueue<>(new StudentHtComparator());
		pq.add(new Student(10,7,12));
		pq.add(new Student(1023,1,1232));
		pq.add(new Student(12,112,32));
		pq.add(new Student(13,21,3));
		pq.add(new Student(1210,217,3212));
		ShowString(pq);
	}
}