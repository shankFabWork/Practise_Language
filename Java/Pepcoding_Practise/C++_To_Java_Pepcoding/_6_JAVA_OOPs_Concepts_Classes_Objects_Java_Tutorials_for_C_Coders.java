import java.util.*; 

public class _6_JAVA_OOPs_Concepts_Classes_Objects_Java_Tutorials_for_C_Coders
{

	static class Rectangle
	{
		int a;
		int b;

		Rectangle(int a,int b)
		{
			this.a = a;
			this.b = b;
		}
	}

	static int area(Rectangle r)
	{
		return r.a*r.b;
	}
	public static void main(String []args)
	{
		Rectangle r = new Rectangle(2,3);
		System.out.print(area(r));
	}
}