
public class testRemove {
	public static void main(String[] args){
		LinkedList origin = new LinkedList("3",new LinkedList("2",new LinkedList("4",new LinkedList("7",new LinkedList("1",new LinkedList("7",new LinkedList("5",null)))))));
		System.out.println(origin.toString());
		origin.removeLastSeven(null);
		System.out.println(origin.toString());
	}
}
