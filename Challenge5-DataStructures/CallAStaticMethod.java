//@author dyang42
/**
 * Prints out only lines that contain an email address Each printed line is
 * justified to right by prepending the text with '.' characters The minimum
 * width of the line including padding is 40 characters. See the test case for
 * example input and expected output.
 */
class CallAStaticMethod {

	public static void main(String[] args) {

		while (!TextIO.eof()) {
			String line = TextIO.getln();
			// Use ExampleClassMethods
			// 'isEmailAddress' and 'createPadding' to complete this method
			if (ExampleClassMethods.isEmailAddress(line)){
				TextIO.put(ExampleClassMethods.createPadding('.', (40-line.length())));
				TextIO.putln(line);
			}
			
		}

	}
}
