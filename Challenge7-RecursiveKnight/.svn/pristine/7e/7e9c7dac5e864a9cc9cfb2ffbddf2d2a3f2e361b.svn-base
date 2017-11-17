/**
 * 
 * @author dyang42
 *
 */
public class MolecularSort {

	/** Sorts each xyz coordinate using it's Z value (coord[i][2] <= coord[j][2] for i<j). */
	static void sortCoordsByZ(double[][] coords) {
		// TODO: Implement this wrapper method.
		//All the work is performed by recursiveSort
		recursiveSort(coords, 0, coords.length-1);
	}

	/**
	 * recursively sorts coordinates entries by their z value. Entries between
	 * lo and hi inclusive are considered.
	 */
	static void recursiveSort(double[][] coords, int lo, int hi) {
		// TODO: write the four lines of a recursive selection sort here.
		if (lo<hi){
			int minIndex = findIndexOfZMinimum(coords, lo, hi);
			swap(coords, minIndex, lo);
			recursiveSort(coords, lo+1, hi);
		}
	}

	/**
	 * returns the index of the entry with the lowest Z value. Entries between
	 * lo and hi inclusive are considered.
	 */
	static int findIndexOfZMinimum(double[][] coords, int lo, int hi) {
		if (lo == hi)
			return lo;
		double current = coords[lo][2];
		int restMinIndex = findIndexOfZMinimum(coords, lo+1, hi);
		double restMin = coords[restMinIndex][2];
		if (current <= restMin)
			return lo;
		else
			return restMinIndex;
		 // TODO: Replace this with your three lines of recursive code
	}
	

	/* Swaps the (x,y and z) values of the i-th and j-th coordinates.*/
	static void swap(double[][] coords, int i, int j) {
		// TODO: write your swap implementation here
		double[] temp = coords[i];
		coords[i] = coords[j];
		coords[j] = temp;
	}
}
