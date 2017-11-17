/**
 * A program to run a simple survey and report the results. See MovieSurvey.txt
 * for more information. TODO: add your netid to the line below
 * 
 * @author dyang42
 */
public class MovieSurvey {
	public static void main(String[] arg) {
		// TODO: Write your program here
		// Hints :
		// Formatted output
		// http://math.hws.edu/javanotes/c2/s4.html#basics.4.4
		TextIO.putln("Welcome. We're interested in how people are watching movies this year.\n"
				+ "Thanks for your time. - The WRITERS GUILD OF AMERICA.\n"
				+ "Please tell us about how you've watched movies in the last month.");
		TextIO.putln("How many movies have you seen at the cinema?");
		int cinema = TextIO.getlnInt();
		TextIO.putln("How many movies have you seen using a DVD or VHS player?");
		int DVD = TextIO.getlnInt();
		TextIO.putln("How many movies have you seen using a Computer?");
		int computer = TextIO.getlnInt();
		int total = cinema+DVD+computer;
		double cinemaFraction = (double)cinema/(double)total*100;
		double notCinemaFraction = 100-cinemaFraction;
		TextIO.putln("Summary: "+cinema+" Cinema movies, "+DVD+" DVD/VHS movies, "+computer+" Computer movies");
		TextIO.putln("Total: "+total+" movies");
		System.out.printf("Fraction of movies seen at a cinema: %.2f%%\n",cinemaFraction);
		TextIO.putf("Fraction of movies seen outside of a cinema: %.2f%%",notCinemaFraction);
		
		// Don't just copy paste the expected output
		// For grading purposes your code may be tested
		// with other input values.
	}
}
