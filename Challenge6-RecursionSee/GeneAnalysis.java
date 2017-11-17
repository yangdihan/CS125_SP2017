/**
 * @author dyang42
 *
 */
public class GeneAnalysis
{
	/** Wrapper method. Returns the length of the longest 
	 * common subsequence
	 */
	public static int score(String gene1, String gene2)
	{
		int len1 = gene1.length();
		int len2 = gene2.length();
		char[] char1 = gene1.toCharArray();
		char[] char2 = gene2.toCharArray();
		return S(char1,char2,len1-1,len2-1);
		// Hint: Use toCharArray() to convert each string to a char array.
		 // call your recursive implementation here with
		// the genes as char arrays, starting at the end of each gene.
	}
	public static int S(char[] char1, char[] char2, int index1, int index2){
		if (index1 < 0 || index2 < 0)
			return 0;
		int max;
		int a = S(char1,char2,index1-1,index2);
		int b = S(char1,char2,index1,index2-1);
		int c = S(char1,char2,index1-1,index2-1);
		if ((char1[index1] == char2[index2])){
			//System.out.println("same");
			max = Math.max(a,Math.max(b, c+1));
		}
		else{
			max = Math.max(a,Math.max(b, c));
		}
		return max;
	}
	/** Implements longest common subsequence recursive search
The recursive case is defined as
					S(i-1, j)
S(i,j) = max {		S(i,j-1)
					S(i-1,j-1)
					S(i-1,j-1) +1 if gene1[i] = gene2[j]

NB  0<=i < gene1.length
    0<=j < gene2.length

You need to figure out the base case.
	 * */
//	define a private recursive Class method 'score' that 
//	returns an integer the score.
//	The method should take four parameters- 
//	two char arrays and two integers (gene1,gene2,i,j)
//	i and j are the indices into gene1 and gene2 respectively.

}
// Use local variables to store a recursive result so that you  do not need to calculate it again.

// Do not use a loops.
