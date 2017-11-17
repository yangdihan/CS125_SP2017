//@author dyang42
/**
 * Create a class 'Geocache' with two private instance variables 'x' 'y' of type double and a private integer 'id'
 * .
 * A class variable 'count' will also be required to count the number of times a Geocache object has been created (instantiated).
 * Create two constructors - one which takes two double parameters (the initial values of x,y). The
 * second constructor will take another Geocache and initialize itself based on that geocache.
 * 
 * For both constructors set the Geocache's id to the current value of count (thus the first geocache will have the value zero)
 * when the Geocache is created, then increment the count value. 
 * 
 * Also create 'resetCount()' and getNumGeocachesCreated() which returns an int - the number of geocaches created since 
 * resetCount() method was called.
 * 
 * Create an equals method that takes an object reference and returns true if the given object equals this object.
 * Hint: You'll need 'instanceof' and cast to a (Geocache)
 * 
 * Create a toString() method that returns a string representation of this object in the form '(x,y)' where 'x' and 'y'
 * are the current values of x,y.
 * 
 * Create the four getX/getY/setX/setY methods for x,y.
 * However the setX() method will only change the Geocache's x value if the given value is between -1000 and 1000 exclusive (i.e. -1000<x<1000).
 * If the value is outside of this range, the new value is ignored and the Geocache's x value remains unchanged.
 *   
 * Create a get method for id.
 * 
 */
class Geocache {
	
	//declaration:
	private double x = 0;
	private double y = 0;
	private int id;
	private static int count = 0;
	
	//constructors:
	public Geocache(double initialX, double initialY){
		setX(initialX);
		setY(initialY);
		this.id = count;
		count += 1;
	}
	public Geocache(Geocache anotherGeocache){
		setX(anotherGeocache.getX());
		setY(anotherGeocache.getY());
		this.id = count;
		count += 1;
	}
	
	//getters:
	public double getX(){
		return this.x;
	}
	public double getY(){
		return this.y;
	}
	public int getId(){
		return this.id;
	}
	
	//setters:
	public void setX(double inputX){
		if (inputX > -1000 && inputX < 1000){
			x = inputX;
		}
	}
	public void setY(double inputY){
		y = inputY;
	}

	public static void resetCount(){
		count = 0;
	}
	public static int getNumGeocachesCreated(){
		return count;
	}
	public boolean equals(Geocache anotherGeocache){
		boolean result = false;
		if(anotherGeocache instanceof Geocache){
			if((anotherGeocache.getX() == this.getX()) && (anotherGeocache.getY() == this.getY())){
				result = true;
			}
		}
		return result;
	}
	public String toString(){
		String result = "(" + getX() + "," + getY() + ")";
		return result;
	}
	

}






