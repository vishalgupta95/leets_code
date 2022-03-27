// C++ implementation of largest triplet
// multiplication
/*
We will use priority queue here. 

Insert arr[i] in the priority queue
As the top element in priority queue is largest so pop it and store it as x. Now the top element in the priority queue will be the second largest element in subarray arr[0…i] pop it and store as y. Now the top element is third largest element in subarray arr[0…i] so pop it and store it as z.
Print x*y*z
Reinsert x, y, z.

*/
#include <bits/stdc++.h>
using namespace std;

// Prints the product of three largest numbers
// in subarray arr[0..i]
void LargestTripletMultiplication(int arr[], int n)
{
	// call a priority queue
	priority_queue<int> q;

	// traversing the array
	for (int i = 0; i < n; i++) {
		// pushing arr[i] in the array
		q.push(arr[i]);

		// if less than three elements are present
		// in array print -1
		if (q.size() < 3)
			cout << "-1" << endl;
		else {
			// pop three largest elements
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			int z = q.top();
			q.pop();

			// Reinsert x, y, z in priority_queue
			int ans = x * y * z;
			cout << ans << endl;
			q.push(x);
			q.push(y);
			q.push(z);
		}
	}
	return;
}

// Driver Function
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	LargestTripletMultiplication(arr, n);
	return 0;
}
