//@author dyang42
public class Stack {
	private String[] data = new String[0];
	/** Adds a value to the top of the stack.*/
	public void push(String value){
		String[] newData = new String[data.length+1];
		newData[0] = value;
		if (data.length>0){
			for (int i=0; i<data.length; i++){
				newData[i+1] = data[i];
			}
		}
		data = newData;
	}
	
	/** Removes the topmost string. If the stack is empty, returns null. */
	public String pop() {
		String result;
		if (data.length != 0){
			result = data[0];
			String[] newData = new String[data.length-1];
			for (int i=0; i<data.length-1; i++){
				newData[i] = data[i+1];
			}
			data = newData;
		}
		else result = null;
		return result;
	}
	
	/** Returns the topmost string but does not remove it. If the stack is empty, returns null. */
	public String peek() {
		if (data.length != 0)
			return data[0];
		else
			return null;
	}
	
	/** Returns true iff the stack is empty */
	public boolean isEmpty() {
		return (data.length == 0);
	}

	/** Returns the number of items in the stack. */
	public int length() {
		return (data.length);
	}
	
	/** Returns a string representation of the stack. Each string is separated by a newline. Returns an empty string if the stack is empty. */
	public String toString() {
		String result = "";
		for (int i=data.length-1; i>=0; i--){
			result += data[i];
			result += "\n";
		}
		return result;
	}
}
