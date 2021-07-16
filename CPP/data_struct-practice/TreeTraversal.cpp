/******************************************************************************
 *  Name:    Silver
 *  NetID:   199211
 *  Precept: P01A
 *
 *  Description:  Use Three methods to traverse a tree 
 * 				  And three methods to build a tree
 *				  Two build methods are recursion and one is loop
 *                Silver initiated this tradition in 2021.
 *
 *  Written:       16/07/2021
 *  Last updated:  16/07/2021
 *
 *  % g++ TreeTraversal.cpp -o TreeTraversal
 *  % ./TreeTraversal < Input_1.txt
 *  1 2 3 4 5 6 7 8 9
 *      
 ******************************************************************************/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode* leftchild;
	TreeNode* rightchild;
	TreeNode() :data(0), leftchild(NULL), rightchild(NULL) {}
	TreeNode(int x): data(x), leftchild(NULL), rightchild(NULL) {}
};

// Preorder traversal version 1
void goToLeft_1(TreeNode* p,stack<TreeNode*> &s) {
	while (p)
	{
		cout << p->data << " ";
		s.push(p->rightchild);
		p = p->leftchild;
	}
}
void preorderTraversal_1(TreeNode* root) {
	stack<TreeNode*> s;
	while (true)
	{
		goToLeft_1(root, s);
		if (s.empty()) break;
		root = s.top();
		s.pop();
	}
}

// Preorder traversal version 2
void preorderTraversal_2(TreeNode* x)
{
	stack<TreeNode*> s;
    s.push(x);
    while(!s.empty())
    {
        x=s.top();
        s.pop();
        if(x==NULL)
        {
            continue;
        }
        else
        {
            cout<<x->data<<" ";
            s.push(x->rightchild);
            s.push(x->leftchild);
        }
    }
}
       
// Middle order traversal
void goToLeft_2(TreeNode* p,stack<TreeNode*> &s) {
	while (p)
	{
		s.push(p);
		p = p->leftchild;
	}
}
void middleOrderTraversal(TreeNode* root) {
	stack<TreeNode*> s;
	while (true)
	{
		goToLeft_2(root, s);
		if (s.empty()) break;
		root = s.top();
		s.pop();
		cout << root->data << " ";
		root = root->rightchild;
	}
}

// Level traversal 
void levelTraversal(TreeNode* x) {
	queue<TreeNode*> q;
	if (x == NULL)
		return; 
	q.push(x);
	while (true)
	{
		x = q.front();
		q.pop();
		cout << x->data << " ";
		if (x->leftchild) q.push(x->leftchild);
		if (x->rightchild) q.push(x->rightchild);
		if (q.empty()) break;
	}
}

// Build a Tree like this
//   				1
//                 |
//               /   \
//             2		3
//             |
//           /   \ 
//         4		5
//         |
//       /   \
//     7		8
//     |
//   /
// 9
TreeNode* buildTree_1(vector<TreeNode *> &v, TreeNode *x) {
	if (v.empty())	
		return x;
	else	
		x-> leftchild = v.front(), v.erase(v.begin());
	if (v.empty())	
		return x;
	else	
		x->rightchild = v.front(), v.erase(v.begin());
	buildTree_1(v, x-> leftchild);
	buildTree_1(v, x->rightchild);
	return x;
}

// Build a Tree like this
// 				   1
//				   |
//			/		       \
//		   2			    3
//		   |				|
//	    /	  \			  /   \
//	  4		   5		6		7
//	  |
//  /   \
// 8	 9
TreeNode* buildTree_0(vector<TreeNode *> &v) {
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
	x-> leftchild = buildTree_0( left);
	x->rightchild = buildTree_0(right);
	return x;
}

// Build a Tree like this 
// 				   1
//				   |
//			/		       \
//		   2			    3
//		   |				|
//	    /	  \			  /   \
//	  4		   5		6		7
//	  |
//  /   \
// 8	 9
TreeNode* buildTree_2(vector<TreeNode *> &v) {
	TreeNode *root = v.size()? v[0] : NULL;
	int i, j, n;
	for (i = 0, j = 1, n = v.size(); j < n;) {
		v[i]-> leftchild = v[j], j++;
		if (j < n) 
			v[i]->rightchild = v[j], j++;
		i++;
	}
	return root;
}

// Build a tree as level order based on what you input, and you should end your input with -1
TreeNode* buildTreeByInput() {
	cout << "Please Enter Some Number:" << endl;
	vector<TreeNode *> v(0);
	int val;
	while (cin >> val) {
		if (val == -1)	break;
		v.push_back(new TreeNode(val));
	}
	return  buildTree_2(v);
}

int main(void) {
	TreeNode *root = buildTreeByInput();
	levelTraversal(root);
	return 0;
}
