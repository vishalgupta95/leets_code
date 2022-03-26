//Count the number of visible nodes in Binary Tree

/*

Given a Binary tree, the task is to find the number of visible nodes in the given binary tree. A node is a visible node if, in the path from the root to the node N, there is no node with greater value than N’s, 
Examples: 

Input:
      5
     /  \
   3     10
  /  \   /
20   21 1

Output: 4 
Explanation:
There are 4 visible nodes. 
They are:
5: In the path 5 -> 3, 5 is the highest node value.
20: In the path 5 -> 3 -> 20, 20 is the highest node value.
21: In the path 5 -> 3 -> 21, 21 is the highest node value.
10: In the path 5 -> 10 -> 1, 10 is the highest node value. 

Approach: The idea is to first traverse the tree. Since we need to see the maximum value in the given path, the pre-order traversal is used to traverse the given binary tree. While traversing the tree, we need to keep the track of the maximum value of the node that we have seen so far. If the current node is greater or equal to the max value, then increment the count of the visible node and update the max value with the current node value. 
Below is the implementation of the above approach:  

*/

// C++ implementation to
// count the number of
// visible nodes in the
// binary tree
#include <bits/stdc++.h>
using namespace std;

// Node containing the
// left and right child of
// current node and the key value
struct Node
{
	int data;
	Node *left, *right;
};

/* Utility that allocates a
new node with the given key and
NULL left and right pointers. */
struct Node* newnode(int data)
{
	struct Node* node = new (struct Node);
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Variable to keep the track
// of visible nodes
int countNode = 0;

// Function to perform the preorder traversal
// for the given tree
void preOrder(Node* node, int mx)
{
	// Base case
	if (node == NULL)
	{
		return;
	}

	// If the current node value is greater
	// or equal to the max value,
	// then update count variable
	// and also update max variable
	if (node->data >= mx)
	{
		countNode++;
		mx = max(node->data, mx);
	}

	// Traverse to the left
	preOrder(node->left, mx);

	// Traverse to the right
	preOrder(node->right, mx);
}

// Driver code
int main()
{
	struct Node* root = newnode(5);

	/*
			5
		/ \
		3	 10
		/ \ /
	20 21 1
*/

	root->left = newnode(3);
	root->right = newnode(10);

	root->left->left = newnode(20);
	root->left->right = newnode(21);

	root->right->left = newnode(1);

	preOrder(root, INT_MIN);

	cout << countNode;
}

// This code is contributed by gauravrajput1
