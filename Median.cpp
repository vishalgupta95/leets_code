//Median in a stream of integers (running integers
/*
Given that integers are read from a data stream. Find median of elements read so for in an efficient way. For simplicity assume, there are no duplicates. For example, let us consider the stream 5, 15, 1, 3 … 
 

After reading 1st element of stream - 5 -> median - 5
After reading 2nd element of stream - 5, 15 -> median - 10
After reading 3rd element of stream - 5, 15, 1 -> median - 5
After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
Making it clear, when the input size is odd, we take the middle element of sorted data. If the input size is even, we pick the average of the middle two elements in the sorted stream.
Note that output is the effective median of integers read from the stream so far. 
Such an algorithm is called an online algorithm. Any algorithm that can guarantee the 
output of i-elements after processing i-th element, is said to be online algorithm. 
Let us discuss three solutions to the above problem.

solution
Method 1: Insertion Sort
If we can sort the data as it appears, we can easily locate the median element. Insertion Sort is one such online algorithm that sorts the data appeared so far. At any instance of sorting, say after sorting i-th element, the first i elements of the array are sorted. The insertion sort doesn’t depend on future data to sort data input till that point. In other words, insertion sort considers data sorted so far while inserting the next element. This is the key part of insertion sort that makes it an online algorithm.
However, insertion sort takes O(n2) time to sort n elements. Perhaps we can use binary search on insertion sort to find the location of the next element in O(log n) time. Yet, we can’t do data movement in O(log n) time. No matter how efficient the implementation is, it takes polynomial time in case of insertion sort.
Interested readers can try the implementation of Method 1.
*/

// This code is contributed by Anjali Saxena

#include <bits/stdc++.h>

using namespace std;

// Function to find position to insert current element of
// stream using binary search
int binarySearch(int arr[], int item, int low, int high)
{
	if (low >= high) {
		return (item > arr[low]) ? (low + 1) : low;
	}

	int mid = (low + high) / 2;

	if (item == arr[mid])
		return mid + 1;

	if (item > arr[mid])
		return binarySearch(arr, item, mid + 1, high);

	return binarySearch(arr, item, low, mid - 1);
}

// Function to print median of stream of integers
void printMedian(int arr[], int n)
{
	int i, j, pos, num;
	int count = 1;

	cout << "Median after reading 1"
		<< " element is " << arr[0] << "\n";

	for (i = 1; i < n; i++) {
		float median;
		j = i - 1;
		num = arr[i];

		// find position to insert current element in sorted
		// part of array
		pos = binarySearch(arr, num, 0, j);

		// move elements to right to create space to insert
		// the current element
		while (j >= pos) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = num;

		// increment count of sorted elements in array
		count++;

		// if odd number of integers are read from stream
		// then middle element in sorted order is median
		// else average of middle elements is median
		if (count % 2 != 0) {
			median = arr[count / 2];
		}
		else {
			median = (arr[(count / 2) - 1] + arr[count / 2])
					/ 2;
		}

		cout << "Median after reading " << i + 1
			<< " elements is " << median << "\n";
	}
}

// Driver Code
int main()
{
	int arr[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printMedian(arr, n);

	return 0;
}

