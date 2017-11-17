package Default;
public class Trail {
	//components
	private String name;
	private int rating;
	private double latitude;
	private double longtitude;
	private String state;
	private boolean haveHiked;
	private String[] landmarks;
	//constructor
	public Trail(String name, int rating, double latitude, double longtitude, String state, boolean haveHiked,
			String[] landmarks) {
		this.name = name;
		this.rating = rating;
		this.latitude = latitude;
		this.longtitude = longtitude;
		this.state = state;
		this.haveHiked = haveHiked;
		this.landmarks = landmarks;
	}
	//getter
	public String getName() {return name;}
	public int getRating() {return rating;}
	public double getLatitude() {return latitude;}
	public double getLongtitude() {return longtitude;}
	public String getState() {return state;}
	public boolean getHavehiked() {return haveHiked;}
	public String[] getLandmarks() {return landmarks;}
	//setter
	public void setName(String name) {this.name = name;}
	public void setRating(int rating) {
		if (rating >= 0 && rating <= 5) {
			this.rating = rating;
		} else {
			throw new IllegalArgumentException("The rating entered is out of range");
		}
	}
	public void setLatitude(double latitude) {this.latitude = latitude;}
	public void setLongtitude(double longtitude) {this.longtitude = longtitude;}
	public void setState(String state) {this.state = state;}
	public void setHaveHiked(boolean haveHiked) {this.haveHiked = haveHiked;}
	public void setLandmarks(String[] landmarks) {this.landmarks = landmarks;}
	//toString
	public String toString(){
		String hiked = "";
		if(this.getHavehiked())
			hiked += "✅️ ";
		else
			hiked += "❓ ";
		String rate = "";
		for (int i=0; i<this.getRating(); i++){
			rate += "⭐️";
		}
		String landMarkList = "";
		for (int i=0; i<this.landmarks.length; i++){
			landMarkList += this.landmarks[i] + "-->";
		}
		String output = hiked + "Name: " + this.getName() +"  " + "\nRating: " + rate + 
		"\n"+ "Latitude: " + this.getLatitude() +"  " + "Longtitude: "
		+ this.getLongtitude() + "  " + "State: " + this.getState() + "\n" 
		+ "Landmarks: "+ landMarkList+"\n---------------------------------------\n";
		return output;
	}
	
	public double getDistance(Trail other){
		double centralAngle = Math.acos(Math.sin(getLatitude())*Math.sin(other.getLatitude())
				+ Math.cos(getLatitude())*Math.cos(other.getLatitude())*Math.cos(Math.abs(getLongtitude())-other.getLongtitude()));
		double distance = 3959*centralAngle;
		return distance;
	}

}

