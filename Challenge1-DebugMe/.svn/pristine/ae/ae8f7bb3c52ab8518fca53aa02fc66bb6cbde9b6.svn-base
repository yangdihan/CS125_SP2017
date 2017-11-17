
/**
 * A program to calculate a factorial. The given code may contain errors. Fix the
 * given code and add additional code to calculate a factorial and pass the unit
 * tests. Hint sometimes an 'int' just 'aint big enough.
 * 
 * @see Factorial-ReadMe.txt for details on how to complete this program.
 * @author dyang42
 */
public class Factorial {
	public static void main(String[] args) {
		int max = 0;
		int input = 0;
		while (max < 1 || max >= 21) {
			System.out.println("Enter a number between 1 and 20 inclusive.");
			max = TextIO.getlnInt();
			input = max;
		}
		long answer = 1;
		while (max >= 1){
			answer = answer*max;
			max = max-1;
		}
		System.out.print(input + "! = " + answer);
	}
}
