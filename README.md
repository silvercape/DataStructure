# Day 04

Today I learn Quick Union

## Part 1

First we should talk about the method `static int discrete(double[] a);` in `StdRandom`

```java
/**
 *You give a double array, give a rata for a number that you want the number appear.
 * For example, a[10] = {0, 0, 0, 0.25, 0.25, 0.25, 0.25, 0, 0, 0 }
 * So 3, 4, 5, 6 may appear once per four times
 */
public class Test {
    public static void main(String[] args) {
        double a[] = {0, 0, 0, 0.25, 0.25, 0.25, 0.25, 0, 0, 0 };
        int ans = StdRandom.discrete(a);
        StdOut.println(ans);
    }
}
```

But I see the source code, and find it hard to figure out its correctness.

```java
 	/**
     * Returns a number from a discrete distribution: i with probability a[i].
     * throws IllegalArgumentException if sum of array entries is not (very nearly) equal to 1.0
     * throws IllegalArgumentException unless [i] >= 0.0for each index i
     */
    public static int discrete(double[] a) {
        double EPSILON = 1E-14;
        double sum = 0.0;
        for (int i = 0; i < a.length; i++) {
            if (!(a[i] >= 0.0)) throw new IllegalArgumentException("array entry " + i + " must be nonnegative: " + a[i]);
            sum = sum + a[i];
        }
        if (sum > 1.0 + EPSILON || sum < 1.0 - EPSILON)
            throw new IllegalArgumentException("sum of array entries does not approximately equal 1.0: " + sum);

        // the for loop may not return a value when both r is (nearly) 1.0 and when the
        // cumulative sum is less than 1.0 (as a result of floating-point roundoff error)
        while (true) {
            double r = uniform();
            sum = 0.0;
            for (int i = 0; i < a.length; i++) {
                sum = sum + a[i];
                if (sum > r) return i;
            }
        }
    }

```

$$
Assume\ every\ number's\ rate\ is\ p_{i}.\\When\ a\ number\ k\ is\ choosen,\ it\ means\ \sum^{k-1}_{i=0}p_{i}\ \le\ while  \sum^{k}_{i=0}p_{i}\ >r\\So\ it\ means\ r\ appears\ in\ [\ \sum^{k-1}_{i=0}p_{i},\ \sum^{k-1}_{i=0}p_{i}+p_{k})
$$

$$
It\ equals\ that\ give\ a\ random\ number\ and\ ask\ for\ the\ rate\ it\ appears\ in\ [\ a,\ b)\\
$$

$$
Both \ a \ and\ b\ is\ in\ [\ 0,\ 1\ ), \ so\ the\ rate\ is\ the\ length\ of\ [\ a,\ b)\\
$$

$$
That\ is\ |\ b\ -\ a\ |,\ which\ is\ p_{k}\ as\ well.
$$

