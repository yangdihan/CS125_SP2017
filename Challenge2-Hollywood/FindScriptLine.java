/**
 * A program to search for specific lines and print their line number.
 * See FindScriptLine.txt for more details
 * TODO: add your netid to the line below
 * @author dyang42
 */
public class FindScriptLine {

	public static void main(String[] args) {
		TextIO.putln("Please enter the word(s) to search for");
		String keyword = TextIO.getlnString();
		String KEYWORD = keyword.toUpperCase();
		String line;
		String LINE;
		int index = 0;
		TextIO.putln("Searching for '"+keyword+"'");
		TextIO.readFile("thematrix.txt");
		while (TextIO.eof() == false){
			line = TextIO.getln();
			index++;
			if (line.length() == 0){
				line = TextIO.getln();
				index++;
			}
			LINE = line.toUpperCase();
			if (LINE.indexOf(KEYWORD) >= 0){
				TextIO.putln(index+" - "+line.trim());
			}
			
		}
		TextIO.putln("Done Searching for '"+keyword+"'");
// TODO: Implement the functionality described in FindScriptLine.txt
// TODO: Test your code manually and using the automated unit tests in FindScriptLineTest		
	}
}
