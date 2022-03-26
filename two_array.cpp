// C++ implementation to check if
// two arrays can be made equal

#include <bits/stdc++.h>
using namespace std;

// Function to check if array B
// can be made equal to array A
bool canMadeEqual(int A[],
				int B[], int n)
{
	// sort both the arrays
	sort(A, A + n);
	sort(B, B + n);

	// Check if both the arrays
	// are equal or not
	for (int i = 0; i < n; i++)
		if (A[i] != B[i])
			return false;
	return true;
}

// Driver Code
int main()
{
	int A[] = { 1, 2, 3 };
	int B[] = { 1, 3, 2 };
	int n = sizeof(A) / sizeof(A[0]);
	if (canMadeEqual(A, B, n))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
