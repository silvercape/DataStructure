/******************************************************************************
 *  Name:    Silver
 *  NetID:   199211
 *  Precept: P03A
 *
 *  Description:  Creat a NewtonSqrt class.
 *                Silver initiated this tradition in 2021.
 *
 *  Written:       17/07/2021
 *  Last updated:  17/07/2021
 *
 *  % javac-algs4 NewtonSqrt.java
 *  % java-algs4 NewtonSqrt < Input.txt
 *      Please enter a number:
 *      Now you input 4.0
 *      And sqrt(4.0) is 2.0
 *      
 ******************************************************************************/
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;


public class NewtonSqrt {
    public static void main(String[] args) {
        StdOut.println("Please enter a number:");
        double x = StdIn.readDouble();
        StdOut.println("Now you input " + x);
        StdOut.println("And sqrt(" + x + ") is " + sqrt(x));
    }
    public static double sqrt(double c) {
        if (c < 0) return Double.NaN;
        double err = 1e-15;
        double t = c;
        while (Math.abs(t - c/t) > err * t)
            t = (c / t + t) / 2.0;
        return t;
    }
}

