/******************************************************************************
*  Name:    Silver
*  NetID:   199211
*  Precept: P01A
*
*  Description:  Creat a BinarySearch class.
*                Silver initiated this tradition in 2021.
*
*  Written:       17/07/2021
*  Last updated:  17/07/2021
*
*  % javac-algs4 BinarySearch.java
*  % java-algs4 BinarySearch < Input.txt
*      
*      
******************************************************************************/
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;


public class BinarySearch {
    private static int[] a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    public static void main(String[] args) {
        StdOut.println("Please enter a number:");
        int n = StdIn.readInt();
        int index = rank(n, a);
        if ( index == -1)
            StdOut.println("Your number is not in the array.");
        else 
            StdOut.println("Your number is in the " + (index + 1) + "th position of the array.");
    }
    public static int rank(int key, int[] a) {
        return rank(key, a, 0, a.length-1);
    }

    public static int rank(int key, int[] a, int lo, int hi) {
        if (lo > hi)    return -1;
        int mid = lo + (hi - lo) / 2;
        if      (key < a[mid])  return rank(key, a, lo, mid - 1);
        else if (key > a[mid])  return rank(key, a, mid + 1, hi);
        else                    return mid;
    }

    public static boolean isPrime(int x) {
        if (x < 2)  return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)  return false;
        }
        return true;
    }
}