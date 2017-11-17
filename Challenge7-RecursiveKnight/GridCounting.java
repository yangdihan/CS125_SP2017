/**
 * 
 * @author dyang42
 *
 */
public class GridCounting {
	/** Returns the total number of possible routes (paths) from
	 * (x,y) to (tx,ty).
	 * There are only three valid kinds of moves:
	 *  Increment x by one.
	 *  Increment x by two.
	 *  Increment y by one.
	 *  
	 *  Hint: You'll need to test two base cases.
	 */
	public static int count(int x,int y, int tx, int ty) {
		if (x > tx || y > ty)
			return 0;
		if (x == tx)
			return 1;
		if (y == ty){
			if (tx-x == 1)
				return 1;
			else if (tx-x == 2)
				return 2;
			else
				return count(x+1, y, tx, ty) + count(x+2, y, tx, ty);
		}
		int x1 = count(x+1, y, tx, ty);
		int x2 = count(x+2, y, tx, ty);
		int y1 = count(x, y+1, tx, ty);
		return x1+x2+y1;
	}
}
