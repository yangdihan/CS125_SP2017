//@author dyang42
import java.awt.Color;

public class KeyValueMap { // aka Dictionary or Map
	private String[] keys = new String[0];
	private Color[] values = new Color[0];
	/**
	 * Adds a key and value. If the key already exists, it replaces the original
	 * entry.
	 */
	
	public String[] getKeys(){
		return this.keys;
	}
	public Color[] getValues(){
		return this.values;
	}
	
	public void add(String key, Color value) {
		boolean exist = false;
		if (keys.length > 0){
			for (int i=0; i<keys.length; i++){
				exist = (keys[i].equalsIgnoreCase(key));
				if (exist){
					values[i] = value;
					return;
				}
			}
		}
		if (!exist){
			String[] newKeys = new String[keys.length+1];
			Color[] newValues = new Color[values.length+1];
			for (int i=0; i<keys.length; i++){
				newKeys[i] = keys[i];
				newValues[i] = values[i];
			}
			newKeys[keys.length] = key;
			newValues[keys.length] = value;
			keys = newKeys;
			values = newValues;
		}
	}

	/**
	 * Returns particular Color object previously added to this map.
	 */
	public Color find(String key) {
		Color result = null;
		for (int i=0; i<keys.length; i++){
			if (keys[i].equalsIgnoreCase(key)){
				result = values[i];
			}
		}
		return result;
	}

	/**
	 * Returns true if the key exists in this map.
	 */
	public boolean exists(String key) {
		boolean exist = false;
		if (keys.length > 0){
			for (int i=0; i<keys.length; i++){
				exist = (keys[i].equalsIgnoreCase(key));
				if (exist)
					break;
				}
			}
		return exist;
	}

	/**
	 * Removes the key (and the color) from this map.
	 */
	public void remove(String key) {
		String[] newKeys = new String[keys.length-1];
		Color[] newValues = new Color[values.length-1];
		for (int i=0; i<keys.length-1; i++){
			if (keys[i].equalsIgnoreCase(key)){
				for (int j=i; j<keys.length-1; j++){
					newKeys[j] = keys[j+1];
					newValues[j] = values[j+1];
				}
				break;
			}else{
				newKeys[i] = keys[i];
				newValues[i] = values[i];
			}
		}
		keys = newKeys;
		values = newValues;
	}

}
