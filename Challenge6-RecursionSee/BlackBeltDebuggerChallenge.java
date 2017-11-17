/**
 * This class tests your Debugger Fu. Use Debug As > Unit Test on the Test
 * class. You'll need to set breakpoints and single step through the code.
 * @author dyang42
 *
 */

public class BlackBeltDebuggerChallenge {

	/**
	 * Use the Debugger's breakpoints, and the debugger controls to discover the
	 * character you need here to make the test pass.
	 * 
	 * @return the secret character
	 */
	public static char getTrial0Secret() {
		// Warning - the value you need here is specific to you
		return 'a' + 1 + (1788449854 & 7);
	}

	/**
	 * Use the Debugger's breakpoints, and the debugger controls to discover the
	 * character you need here to make the test pass.
	 * 
	 * @return the secret character
	 */
	public static char getTrial1Secret() {
		// Warning - the value you need here is specific to you
		return 'z'-1-(1788449854 >> 2 & 7);
		
		
	}

	
	/**
	 * Use the Debugger's breakpoints, and the debugger controls to discover the
	 * character you need here to make the test pass.
	 * 
	 * @return the secret character
	 */
	public static char getTrial2Secret() {
		// Warning - the value you need here is specific to you
		return 'A' + 18;
	}

	/**
	 * Use the Debugger's breakpoints, and the debugger controls to discover the
	 * character you need here to make the test pass.
	 * 
	 * @return the secret character
	 */
	public static char getTrial3Secret() {
		return 9;
	}
}
