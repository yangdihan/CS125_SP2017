/**
 * Prints sum of odd numbers in a specific format.
 * TODO: add your netid to the line below
 * @author dyang42
 */
public class OddSum { 
/**
Example output if user enters 10:
Max?
1 + 3 + 5 + 7 + 9 = 25
25 = 9 + 7 + 5 + 3 + 1

Example output if user enters 11:
Max?
1 + 3 + 5 + 7 + 9 + 11 = 36
36 = 11 + 9 + 7 + 5 + 3 + 1

 */
 public static void main(String[] args) { 
	 int number = TextIO.getlnInt();
	 int i;
	 int sum = 1;
	 TextIO.putln("Max?");
	 TextIO.put("1 ");
	 for (i=3; i <= number; i+=2){
		 TextIO.put("+ " + i + " ");
		 sum += i;
	 }
	 TextIO.putln("= " + sum);
	 i -= 2;
	 TextIO.put(sum + " = " + i);
	 for (i-=2; i>0; i-=2){
		 TextIO.put(" + " + i);
	 }
  } // end of main method
} // end of class 
