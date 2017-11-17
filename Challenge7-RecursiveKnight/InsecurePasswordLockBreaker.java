/**
 * 
 * @author dyang42
 *
 */
public class InsecurePasswordLockBreaker {

	public static char[] breakLock(InsecurePasswordLock lock) {
		/*char[] key = "ASECRETTHATYOUWILLNOTGUESSTODAY".toCharArray();
		return key;*/
		// write code here to determine the secret password
		// to unlock the given lock object.
		// You do not need to use recursion.
		// Hint: Read the source code of InsecurePasswordLock
		// The lock has a weakness....
		// Understand it and you can write an algorithm to quickly find the
		// secret password
		// (A brute force guess of a 40 character password would take a long
		// time...
		// as there are 26^40 combinations!
		// Your method should find it in a few seconds.

		// Beginner: You should complete this code in less than an hour

		// Advanced Code-Golf: Can you complete this method in 8 lines
		// (excluding the top and bottom given
		// lines and after autoformating your code)
		
		// Crazy Instructor level:
		// I can write a complete albeit-inefficient solution using single while loop :-)
		// expression: while (____){/*NoCodeHere*/}
		//find length
		int i = 0;
		boolean findL = false;
		while (!findL){
			char[] trailL = new char[i+1];
			int ans = lock.open(trailL);
			if (ans != -1)
				break;
			i += 1;
			}
		int Length = i+1;
		char[] trail = new char[Length];
		
		for (int j=0; j<Length; j++){
			int ans = j;
			int k = 0;
			while(ans == j){
				trail[j] = (char) ('A' + k);
				//System.out.println(k);
				//System.out.println((char) ('A' + k));
				ans = lock.open(trail);
				//System.out.println(ans);
				k += 1;
			}
			char correct = (char) ('A' + k -1);
			trail[j] = correct;
		}
		return trail;
		}
	

	public static void main(String[] args) {
		InsecurePasswordLock lock = new InsecurePasswordLock();
		char[] key = breakLock(lock);
		System.out.println(key);
		System.out.println(lock.isUnlocked());
	}
}