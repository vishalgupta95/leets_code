//Reverse even elements in a Linked List

/*
Approach: Reversing the contiguous even elements will not take place when: 
 

The node’s value is odd.
The node’s value is even but adjacent values are odd.
In rest of the cases, the continuous block of even nodes can be reversed.
Below is the implementation of the above approach: 

*/


// C++ implementation of the approach
#include <iostream>
using namespace std;

// Structure of a node of the linked list
struct node {
	int data;
	struct node* next;
};

// Function to create a new node
struct node* newNode(int d)
{
	struct node* newnode = new node();
	newnode->data = d;
	newnode->next = NULL;
	return newnode;
}

// Recursive function to reverse the consecutive
// even nodes of the linked list
struct node* reverse(struct node* head, struct node* prev)
{

	// Base case
	if (head == NULL)
		return NULL;

	struct node* temp;
	struct node* curr;
	curr = head;

	// Reversing nodes until curr node's value
	// turn odd or Linked list is fully traversed
	while (curr != NULL && curr->data % 2 == 0) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	// If elements were reversed then head
	// pointer needs to be changed
	if (curr != head) {

		head->next = curr;

		// Recur for the remaining linked list
		curr = reverse(curr, NULL);
		return prev;
	}

	// Simply iterate over the odd value nodes
	else {
		head->next = reverse(head->next, head);
		return head;
	}
}

// Utility function to print the
// contents of the linked list
void printLinkedList(struct node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 3, 3, 4, 6, 8, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	struct node* head = NULL;
	struct node* p;

	// Constructing linked list
	for (int i = 0; i < n; i++) {

		if (head == NULL) {
			p = newNode(arr[i]);
			head = p;
			continue;
		}
		p->next = newNode(arr[i]);
		p = p->next;
	}

	// Head of the updated linked list
	head = reverse(head, NULL);

	// Printing the reversed linked list
	printLinkedList(head);

	return 0;
}
