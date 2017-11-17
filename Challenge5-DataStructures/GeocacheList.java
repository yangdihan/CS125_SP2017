//@author dyang42
/**
 * Complete the following GeocacheList, to ensure all unit tests pass.
 * There are several errors in the code below
 *
 * Hint: Get the Geocache class working and passing its tests first.
 */
public class GeocacheList {
	private Geocache[] data = new Geocache[0];
	private int size = 0;

	public Geocache getGeocache(int i) {
		return data[i];
	}

	public int getSize() {
		return size;
	}

	public GeocacheList() {
	}

	public GeocacheList(GeocacheList other, boolean deepCopy) {
		this.data = new Geocache[other.data.length];
		if (deepCopy){
			for (int i=0; i<other.data.length; i++){
				data[i] = new Geocache(other.data[i].getX(),other.data[i].getY());
			}
		}
		if (!deepCopy){
			for (int i=0; i<other.data.length; i++){
				this.data[i] = other.data[i];
			}
		}
		this.size = other.size;	
	}

	public void add(Geocache p) {
		size++;
		if (size > data.length) {
			Geocache[] old = data;
			data = new Geocache[size * 2];
			for (int i = 0; i < old.length; i++)
				data[i] = old[i];
		}
		data[size-1] = p;
	}

	public void removeFromTop() {
		size--;
		for (int i = 0; i < data.length-1; i++){
			data[i] = data[i+1];
		}
	}

	public String toString() {
		StringBuffer s = new StringBuffer("GeocacheList:");
		for (int i = 0; i < size; i++) {
			if (i > 0)
				s.append(',');
			s.append(data[i]);
		}
		return s.toString();
	}
}