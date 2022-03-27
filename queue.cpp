/* queue remove

Given a queue q[] and an integer K, the task is to define a method to remove a specific element from the queue q[]. If there are multiple occurrences of element K, then, remove the first one from the queue q[].

Examples:

Input: q[] = {10, 20, 30, 40, 50, 60}, K = 30
Output: {10, 20, 40, 50, 60}
Explanation: After removal of 30, the queue becomes {10, 20, 40, 50, 60}.

Input: q[] = {1, 2, 3, 3}, K = 3
Output: {1, 2, 3}
Explanation: After removal of the first occurrence of 3, the queue becomes {1, 2,  3}. 
*/
// C++ program for the above approach.
#include <bits/stdc++.h>
using namespace std;

// Function to remove an element from
// the queue
void remove(int t, queue<int>& q)
{

	// Helper queue to store the elements
	// temporarily.
	queue<int> ref;
	int s = q.size();
	int cnt = 0;

	// Finding the value to be removed
	while (q.front() != t and !q.empty()) {
		ref.push(q.front());
		q.pop();
		cnt++;
	}

	// If element is not found
	if (q.empty()) {
		cout << "element not found!!" << endl;
		while (!ref.empty()) {

			// Pushing all the elements back into q
			q.push(ref.front());
			ref.pop();
		}
	}

	// If element is found
	else {
		q.pop();
		while (!ref.empty()) {

			// Pushing all the elements back into q
			q.push(ref.front());
			ref.pop();
		}
		int k = s - cnt - 1;
		while (k--) {

			// Pushing elements from front of q to its back
			int p = q.front();
			q.pop();
			q.push(p);
		}
	}
}

// Function to print all the elements
// of the queue.
void print(queue<int> qr)
{
	while (!qr.empty()) {
		cout << qr.front() << " ";
		qr.pop();
	}
	cout << endl;
}

// Driver Code
int main()
{
	queue<int> q;

	// Pushing into the queue
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	print(q);

	// Removing 39 from the queue
	remove(39, q);
	print(q);

	// Removing 30 from the queue
	remove(30, q);
	print(q);
	return 0;
}
