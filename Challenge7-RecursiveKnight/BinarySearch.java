/**
 * 
 * @author dyang42
 *
 */
public class BinarySearch {
	/** Wrapper method. Just runs the recursive search method below for the entire array*/
	public static boolean search(int[] array, int key) {
		return search(array, key, 0, array.length - 1);
	}

	/**
	 * Recursive search using Divide and Conquer approach:
	 * The given array is already sorted so we can very quickly discover if the key is in the array or not.
	 * Hint: For the recursive case check the value at (lo+hi)/2
	 * and proceed accordingly.
	 */
	static boolean search(int[] array, int key, int lo, int hi) {
		if (lo > hi)
			return false;
		int mid = (lo+hi)/2;
		int current = array[mid];
		if (key == current)
			return true;
		else if (key<current)
			return search(array, key, lo, mid-1);
		else
			return search(array, key, mid+1, hi);
	}
}
