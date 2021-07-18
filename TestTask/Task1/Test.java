/******************************************************************************
*  Name:    Silver
*  NetID:   199211
*  Precept: P01A
*
*  Description:  Creat a Test class.
*                Silver initiated this tradition in 2021.
*
*  Written:       18/07/2021
*  Last updated:  18/07/2021
*
*  % javac-algs4 Test.java
*  % java-algs4 Test < Input.txt
*
*
******************************************************************************/
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdIn;

public class Test {
    public static void main(String[] args) {
        int[] j = new int[1];
        for (int i = 0; i < 15; i++) {
            StdOut.println(ff(j ,i));
        }
    }
    public static int  ff(int[] prev, int n) {
        if (n == 0) {
            prev[0] = 1;
            return 0;
        }
        int[] prePrev = new int[1];
        prev[0] = ff(prePrev, n-1);
        return prePrev[0] + prev[0];
    }
}