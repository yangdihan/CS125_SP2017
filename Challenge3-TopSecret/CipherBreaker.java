/**
 * See CipherBreaker.txt for instructions.
 * TODO: add your netid to the line below
 * 
 * @author dyang42
 */
public class CipherBreaker {

	public static void main(String[] args) {
		TextIO.putln("Text?");
		String line = TextIO.getln();
		TextIO.putln(line);
		
		int[] letterHistogram = new int[26];
		int numChar;
        int numDigits = 0;
        int numSpaces = 0;
        int numPunctuations = 0;
        
        String lineLow = line.toLowerCase();
        char[] charLine = lineLow.toCharArray();
        for (int i=0; i<charLine.length; i++){
        	char check = charLine[i];
        	if (check >= 97 && check <= 122){
        		int letterIndex = check-97;
        		letterHistogram[letterIndex] += 1;
        	}
        	else if (check >= 48 && check <= 57){
        		numDigits += 1;
        	}
        	else if (check == 32){
        		numSpaces += 1;
        	}
        	else if (check == 33 || check == 34 || check == 39 || check == 44 || check == 45 || check == 46){
        		numPunctuations += 1;
        	}
        }
        for(int i=0; i<26; i++){
        	if (letterHistogram[i] != 0){
	            numChar = letterHistogram[i];
	            TextIO.putln((char)(i+65) + ":" + numChar);
        	}
        }
        if (numDigits != 0)
        	TextIO.putln("DIGITS:"+numDigits);
        if (numSpaces != 0)
        	TextIO.putln("SPACES:"+numSpaces);
        if (numPunctuations != 0)
        	TextIO.putln("PUNCTUATION:"+numPunctuations);
	}
}