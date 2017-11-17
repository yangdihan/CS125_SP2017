package Default;

public class Node {
	

	public Trail trail;
	public Node next;
	
	public Node(Trail trail, Node next){
		this.trail = trail;
		this.next = next;
	}

	public Node add(Trail newTrail){
		if (this.trail.getName().compareTo(newTrail.getName()) < 0){
			if (this.next == null){
				Node nextNode = new Node(newTrail,null);
				this.next = nextNode;
			}
			else
				this.next.add(newTrail);
			return this;
		}
		else{
			Node prevNode = new Node(newTrail,this);
			return prevNode;
		}
	}
		
	public Node remove(String name){
		if(this.trail.getName().equals(name)) {
			return this.next;
		}
		
		if(this.next != null) {
			if(this.next.trail.getName().equals(name)) {
				this.next = this.next.next;
			} else {
				this.next.remove(name);
			}
			return this;
		} else {
			return this;
		}
	}
	
	public String toString(){
		Node currentNode = this;
		String newString = "" + this.trail.toString() + "\n";
		while(currentNode.next != null){
			newString += this.next.trail.toString() + "\n";
			currentNode = currentNode.next;
		}
		return newString;
	}
	
	
	public int getCount(){
		if(next == null)return 1;
		else return 1 + next.getCount();
	}
	
	
	public String findRating(int newRating){
		String output = "";
		if (this.next == null){
			if (this.trail.getRating() >= newRating)
				return this.trail.toString();
			else
				return "";
		}
		if (this.trail.getRating() >= newRating)
			output += this.trail.toString() +"\n"+ this.next.findRating(newRating);
		else
			output += "\n"+ this.next.findRating(newRating);
		return output;
	}
	
	public String findState(String newState){
		String output = "";
		if (this.next == null){
			if (this.trail.getState().equals(newState) && this.trail.getHavehiked()==false)
				return this.trail.toString();
			else
				return "";
		}
		if (this.trail.getState().equals(newState) && this.trail.getHavehiked()==false)
			output += this.trail.toString() +"\n"+ this.next.findState(newState);
		else
			output += "\n"+ this.next.findState(newState);
		return output;
	}
	
	
	
	public Trail getTrail(String name){
		if(next == null){
			if(this.trail.getName().equals(name)){
				return this.trail;
			}
			return null;
		}
		if(this.trail.getName().equals(name)){
			return this.trail;
		}
		return this.next.getTrail(name);
	}
	
	
	public Node getShortest(Trail other){
		if (next == null){
			return this;
		}
		Node output = this.next.getShortest(other);
		double distance = this.trail.getDistance(other);
		if (this.trail.getName().equals(other.getName())){
			return output;
		}
		if (output.trail.getName().equals(other.getName())){
			return this;
		}
		if (distance < output.trail.getDistance(other)){
			return this;
		}
		return output;
	}
	
	
	
	public String findLandmark(String newLand){
		String testString="";
		for (int i=0; i<this.trail.getLandmarks().length; i++)
			testString += this.trail.getLandmarks()[i];
		if(next == null){
			if(testString.toLowerCase().contains(newLand))
				return "\n" + this.trail.toString();
			else return "";
		} 
		if (testString.toLowerCase().contains(newLand)){
			return this.trail.toString() + "\n" + this.next.findLandmark(newLand);
		}
		else return "\n" + this.next.findLandmark(newLand);
	}

	
	public String findNotYet(){
		if (this.next == null){
			if (this.trail.getHavehiked() == false)
				return this.trail.toString();
			else
				return "";
		}
		if (this.trail.getHavehiked() == false)
			return this.trail.toString() +"\n" + this.next.findNotYet();
		else
			return "\n" + this.next.findNotYet();
	}
}
	

