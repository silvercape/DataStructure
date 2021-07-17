# Day 02

## Reflect 

Modification to the code yesterday, it build a tree just as follows when given numbers 1 2 3 4 5 6 7 8 9

```python
                1
                |
              /   \
            2		3
            |
          /   \ 
        4		5
        |
      /   \
    7		8
    |
  /
9

```

But what I want is another one

```python
				1
				|
			/		\
		2				3
		|				|
	  /	  \			  /   \
	4		5		6		7
	|
  /   \
8		9
```

Although the first one is as the same as the second when Level-Traversal.

I find that I can't divide the `vector<TreeNode *>` to two part for the left and the right.

```c
+---+---+---+---+---+---+---+---+---+---+---+---+
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |
+---+---+---+---+---+---+---+---+---+---+---+---+
  |	  ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
  |	  |   |   |   |   |   |   |   |   |   |   |
  ---------   |   |   |   |   |   |   |   |   |
      |		  |   |   |   |   |   |   |   |   |
      -------------   |   |   |   |   |   |   |
           |          |   |   |   |   |   |   |
    	   ----------------   |   |   |   |   |
               |              |   |   |   |   |
               --------------------   |   |   |
                  |                   |   |   |
                   ------------------------   |
    				   |                      |
     					-----------------------
```

So the left tree of the root 1 is

```
[2, 4, 5, 8, 9, 10, 11]
```

The right tree of the root 1 is 

```
[3, 6, 7, 12]
```

So if assume the `vector<TreeNode *>` is the elements of the root, I should divide all the elements into two vectors. Em....

I would like use Loop rather than recursion.

```
let i = 0

for j in 1 to n-1

​	v[i]. left child = v[j] && j++ 
​	if j <= n-1
​		v[i].right child = v[j] && j++ 
​	i++

```

This is very simple, so I try to modify my code

```cpp
TreeNode* buildTree(vector<TreeNode *> &v) {
	if (v.empty())	return NULL;
	TreeNode *x = v.front();
	v.erase(v.begin());
	TreeNode *tmp = NULL;
	vector<TreeNode *> left, right;
	int i, j, size;
	for (i = 0, j = 1, size = v.size(); i < size; j *= 2 ) {
		// Left  append cnt from 0 to j-1
		for (int cnt = 0; cnt < j && i < size; cnt++, i++)
			left.push_back(v[i]);
		// Right append cnt from 0 to j-1
		for (int cnt = 0; cnt < j && i < size; cnt++, i++)
			right.push_back(v[i]);
	}	
	x-> leftchild = buildTree( left);
	x->rightchild = buildTree(right);
	return x;
}

```

It seems to be a success!