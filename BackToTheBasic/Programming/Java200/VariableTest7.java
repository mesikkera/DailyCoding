public class VariableTest7 {

	public static void main(String[] args) {
		int a=10;
		int b=20;
		int c=a+b;
		System.out.println("1-- Sum: 10 + 20 = "+c);
		int d=10;
		d=d+20;
		System.out.println("2-- Sum: 10 + 20 = "+d);
		String str="Hello! Enjoy Java!";
		System.out.println("3-- Print String: "+str);
		// String Concatenation
		System.out.println("--String Concatenation Test--");
		System.out.println(a+b+" Sum ");
		System.out.println(a+" Sum "+b);
		System.out.println(" Sum "+a+b);
		System.out.println(" Sum "+(a+b));
	}
}