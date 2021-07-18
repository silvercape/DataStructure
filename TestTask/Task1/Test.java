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
import edu.princeton.cs.algs4.StdRandom;

public class Test {
    public static void main(String[] args) {
        // double x, y;
        StdOut.println("Please enter two float numbers:");
        double a[] = {0, 0, 0, 0.25, 0.25, 0.25, 0.25, 0, 0, 0 };
        int ans = StdRandom.discrete(a);
        StdOut.println(ans);
    }
}