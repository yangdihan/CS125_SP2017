/**
 * A program to search for to encrypt and decrypt lines of text. See
 * CaesarCipher.txt
 * Hints: line.charAt( int ) is useful.
 * You'll need loops, and conditions and variables
 * You'll need to read the Test cases to understand how your program should work.
 * Good Programming Hints: "DRY: Don't Repeat Yourself"
 * Try to make your program as short as possible.
 * TODO: add your netid to the line below
 * @author dyang42
 */
public class CaesarCipher {

	public static void main(String[] strings) {
		TextIO.putln("Please enter the shift value (between -25..-1 and 1..25)");
		int encode = TextIO.getlnInt();
		
		while ((encode<-25 || encode == 0 || encode>25) && (encode != -999 && encode != 999)){
			TextIO.putln(encode + " is not a valid shift value.\nPlease enter the shift value (between -25..-1 and 1..25)");
			encode = TextIO.getlnInt();
		}//check encode shifting is in range and not special case, then reenter
		
		if (encode != -999 && encode != 999)
			TextIO.putln("Using shift value of "+encode+"\nPlease enter the source text (empty line to quit)");
		if (encode == 999 || encode == -999)
			TextIO.putln("Using position shift\nPlease enter the source text (empty line to quit)");
		String origin = TextIO.getlnString();//get a string
		
		while (origin.length() != 0){//origin has all case
			String upper = origin.toUpperCase();//upper only upper case
			char[] charArr = upper.toCharArray();//charArr all upper case
			String result = "";//start a empty string for result
			if (encode != -999 && encode != 999){
				for (int i=0;i<charArr.length;i++){
					if (charArr[i] >= 65 && charArr[i] <= 90){
						if (encode>0)
							result += (char)('A' + (charArr[i]-'A'+encode)%26);
						if (encode<0)
							result += (char)('A' + (charArr[i]-'A'+(26+encode))%26);
					}// for +- letter
					else
						result += charArr[i];// for punctuation
				}//create regular result string
			}//for regular encode
			
			if (encode == 999 || encode == -999){
				for (int i=0;i<charArr.length;i++){
					if (charArr[i] >= 65 && charArr[i] <= 90){
						if (encode>0){
							if ((charArr[i]-'A' + i)%26 >= 0)
								result += (char)('A' + (charArr[i]-'A' + i)%26);
							if ((charArr[i]-'A' + i)%26 < 0) 
								result += (char)('A' + 26 + (charArr[i]-'A' + i)%26);
						}
						if (encode<0){
							if ((charArr[i]-'A' - i)%26 >= 0)
								result += (char)('A' + (charArr[i]-'A' - i)%26);
							if ((charArr[i]-'A' - i)%26 < 0) 
								result += (char)('A' + 26 + (charArr[i]-'A' - i)%26);
						}
					}
					else
						result += charArr[i];
				}
			}// for special encode
			TextIO.putln("Source   :"+origin+"\n"
					+ "Processed:"+result+"\n"
					+ "Please enter the source text (empty line to quit)");
			origin = TextIO.getlnString();
		} //for not empty line
	
		TextIO.putln("Bye.");//for empty line	
	}

}

