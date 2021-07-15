/******************************************************************************
 *  Name:    Silver
 *  NetID:   199211
 *  Precept: P01A
 *
 *  Description:  Creat a Union-Find class and solve the connective question.
 *                By the way, this is the first java program for me.
 *                Silver initiated this tradition in 2021.
 *
 *  Written:       14/07/2021
 *  Last updated:  14/07/2021
 *
 *  % javac-algs4 MyUf.java
 *  % java-algs4 MyUf < tinyUf.txt
 *  2 components
 *      
 ******************************************************************************/
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;


public class MyUf {
    private int[] id;
    private int count;
    public MyUf(int n) {
        // initial 
        count = n;
        id = new int[n];
        for (int i = 0; i < n; i++)
            id[i] = i;
    }
    public int count() 
    {   return count;   }
    public boolean connected(int p, int q)
    {   return find(p) == find(q);  }
    public int find(int p) 
    {   return id[p];   }
    public void union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;
        
        for (int i = 0; i < id.length; i++)
            if (id[i] == pID)   id[i] = qID;
        count--;
    }

    public static void main(String[] args) {
        int n = StdIn.readInt();
        MyUf myUf = new MyUf(n);
        while (!StdIn.isEmpty()) {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if (myUf.connected(p, q)) 
                continue;
            myUf.union(p, q);
        }
        StdOut.println(myUf.count() + " components");
    }
}
