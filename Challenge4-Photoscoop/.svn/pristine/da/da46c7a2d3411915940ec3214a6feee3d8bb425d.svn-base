/* Manipulates RGB values
 * 
 * Todo: Put your netid (i.e. username) in the line below
 * 
 * @author dyang42
 */

public class RGBUtilities {

/**
 * Extracts the red component (0..255)
 * Hint: see ch13.1.2 Working With Pixels 
 * http://math.hws.edu/javanotes/c13/s1.html#GUI2.1.2
 * 
 * ... also see the notes in READ-ME-FIRST
 * 
 * @param rgb the encoded color int
 * @return the red component (0..255)
 */
	public static int toRed(int rgb) {
		int result = (rgb >> 16) & 0xFF;
		return result; // FIX ME
	}

	public static int toGreen(int rgb) {
		int result = (rgb >> 8) & 0xFF;
		return result; // FIX THIS
	}

	public static int toBlue(int rgb) {
		int result = (rgb) & 0xFF;
		return result; // FIX THIS
	}

	/**
	 * 
	 * @param r the red component (0..255)
	 * @param g the green component (0..255)
	 * @param b the blue component (0..255)
	 * @return a single integer representation the rgb color (8 bits per component) rrggbb
	 */
	static int toRGB(int r, int g, int b) {
		int a = 256*256*r + 256*g + b;
		return a; // FIX THIS
	}

}
