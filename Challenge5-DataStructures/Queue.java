//@author dyang42
public class Queue {
	private double[] data = new double[0];

	/** Adds the value to the front of the queue.
	 * Note the queue automatically resizes as more items are added. */

	public void add(double value) {
		double[] newData = new double[data.length+1];
		newData[0] = value;
		if (data.length>0){
			for (int i=0; i<data.length; i++){
				newData[i+1] = data[i];
			}
		}
		data = newData;
	}
	/** Removes the value from the end of the queue. If the queue is empty, returns 0 */
	public double remove() {
		double result;
		if (data.length != 0){
			result = data[data.length-1];
			double[] newData = new double[data.length-1];
			for (int i=0; i<data.length-1; i++){
				newData[i] = data[i];
			}
			data = newData;
		}
		else result = 0;
		return result;
	}
	
	/** Returns the number of items in the queue. */
	public int length() {
		return data.length;
	}
	
	/** Returns true iff the queue is empty */
	public boolean isEmpty() {
		return (data.length == 0);
	}
	
	/** Returns a comma separated string representation of the queue. */
	public String toString() {
		String result = "";
		for (int i=data.length-1; i>0; i--){
			result += data[i];
			result += ",";
		}
		result += data[0];
		return result;
	}
}
