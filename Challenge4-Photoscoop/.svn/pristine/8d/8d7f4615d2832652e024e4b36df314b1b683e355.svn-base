
/* A class to implement the various pixel effects.
 *
 * Todo: Put your netid (i.e. username) in the line below
 * 
 * @author dyang42
 */
public class PixelEffects {

	/** Copies the source image to a new 2D integer image */
	public static int[][] copy(int[][] source) {
		// Create a NEW 2D integer array and copy the colors across
		// See redeye code below
		int width = source[0].length;
		int height = source.length;
		int[][] result = new int[height][width];
		
		for (int i=0; i<height; i++){
			for (int j=0; j< width; j++){
				result[i][j] = source[i][j];
			}
		}
		return result; // Fix Me
	}
	/**
	 * Resize the array image to the new width and height
	 * You are going to need to figure out how to map between a pixel
	 * in the destination image to a pixel in the source image
	 * @param source
	 * @param newWidth
	 * @param newHeight
	 * @return
	 */
	public static int[][] resize(int[][] source, int newWidth, int newHeight) {
		int orgWidth = source.length;
		int orgHeight = source[0].length;
		int[][] result = new int[newWidth][newHeight];
		double heightScale = (double)orgHeight/newHeight;
		double widthScale = (double)orgWidth/newWidth;
		for (int i = 0; i < newWidth; i++){
			for (int j = 0; j < newHeight; j++) {
				result[i][j] = source[(int)(i*widthScale)][(int)(j*heightScale)];
			}
		}
		return result; // Fix Me
		// Hints: Use two nested for loops between 0... newWidth-1 and 0.. newHeight-1 inclusive.
		// Hint: You can just use relative proportion to calculate the x (or y coordinate)  in the original image.
		// For example if you're setting a pixel halfway across the image, you should be reading half way across the original image too.
	}

	/**
	 * Half the size of the image. This method should be just one line! Just
	 * delegate the work to resize()!
	 */
	public static int[][] half(int[][] source) {
		int orgWidth = source.length;
		int orgHeight = source[0].length;
		int[][] result = resize(source,orgWidth/2,orgHeight/2);
		return result; // Fix Me
	}
	
	/**
	 * Create a new image array that is the same dimesions of the reference
	 * array. The array may be larger or smaller than the source. Hint -
	 * this methods should be just one line - delegate the work to resize()!
	 * 
	 * @param source
	 *            the source image
	 * @param reference
	 * @return the resized image
	 */
	public static int[][] resize(int[][] source, int[][] reference) {
		return resize(source, reference.length, reference[0].length); // Fix Me
	}

	/** Flip the image vertically */
	public static int[][] flip(int[][] source) {
		int width = source.length;
		int height = source[0].length;
		int[][] result = new int[width][height];
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++) {
				result[i][j] = source[i][height-j-1];
			}
		return result;// Fix Me
	}

	/** Reverse the image horizontally */
	public static int[][] mirror(int[][] source) {
		int width = source.length;
		int height = source[0].length;
		int[][] result = new int[width][height];
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++) {
				result[i][j] = source[width-i-1][j];
			}
		return result;// Fix Me
	}

	/** Rotate the image */
	public static int[][] rotateLeft(int[][] source) {
		int width = source.length;
		int height = source[0].length;
		int[][] result = new int[height][width];
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++) {
				result[i][j] = source[width-j-1][i];
			}
		return result;
	}
	
	

	/** Merge the red,blue,green components from two images */
	public static int[][] merge(int[][] sourceA, int[][] sourceB) {
		int result[][] = new int[sourceA.length][sourceA[0].length];
		for (int i=0; i<sourceA.length; i++){
			for (int j=0; j<sourceA[0].length; j++){
				int A = sourceA[i][j];
				int B = sourceB[i][j];
				int r = ((int)(((int)(A>>16) + (int)(B>>16) & 0xFF)/2))<<16;
				int g = ((int)(((int)(A>>8) + (int)(B>>8) & 0xFF)/2))<<8;
				int b = ((int)(((int)(A) + (int)(B) & 0xFF)/2));
				result[i][j] = r + g + b;
			}
		}
		// The output should be the same size as the input. Scale (x,y) values
		// when reading the background
		// (e.g. so the far right pixel of the source is merged with the
		// far-right pixel ofthe background).
		return result;
	}

	/**
	 * Replace the green areas of the foreground image with parts of the back
	 * image
	 */
	public static int[][] chromaKey(int[][] foreImage, int[][] backImage) {
		// If the image has a different size than the background use the
		// resize() method
		// create an image the same as the background size.
		foreImage = resize(foreImage,backImage);
		int result[][] = new int[backImage.length][backImage[0].length];
		for (int i=0; i<backImage.length; i++){
			for (int j=0; j<backImage[0].length; j++){
				int foreColor = foreImage[i][j];
				boolean isGreen = (((int)(foreColor>>8) & 0xFF) != 0);
				result[i][j] = isGreen? backImage[i][j] : foreImage[i][j];
			}	
		}
		return result;
	}

	/** Removes "redeye" caused by a camera flash. sourceB is not used */
	public static int[][] redeye(int[][] source, int[][] sourceB) {

		int width = source.length, height = source[0].length;
		int[][] result = new int[width][height];
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++) {
				int rgb = source[i][j];
				int red = RGBUtilities.toRed(rgb);
				int green = RGBUtilities.toGreen(rgb);
				int blue = RGBUtilities.toBlue(rgb);
				if (red > 4 * Math.max(green, blue) && red > 64)
					red = green = blue = 0;
				result[i][j] = RGBUtilities.toRGB(red, green, blue);
			}

		return result;
	}

	/* Upto you! do something fun to the image */
	public static int[][] funky(int[][] source, int[][] sourceB) {
		int width = source.length, height = source[0].length;
		int[][] result = new int[width][height];
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++) {
				result[i][j] = -source[i][j];
			}
		//invert color lol
		// You need to invent your own image effect
		// Minimum boring requirements to pass autograder:
		
		// Does not ask for any user input and returns a new 2D array
		// Todo: remove this return null
		return result;
	}
}
