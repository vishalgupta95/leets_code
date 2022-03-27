/*
Seating arrangement of N boys sitting around a round table such that two particular boys sit together
Difficulty Level : Easy
Last Updated : 31 Mar, 2021
There are N boys which are to be seated around a round table. The task is to find the number of ways in which N boys can sit around a round table such that two particular boys sit together.
Examples: 
 

Input: N = 5 
Output: 48 
2 boy can be arranged in 2! ways and other boys 
can be arranged in (5 – 1)! (1 is subtracted because the 
previously selected two boys will be considered as a single boy now) 
So, total ways are 2! * 4! = 48.
Input: N = 9 
Output: 80640 
 */

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the total count of ways
int Total_Ways(int n)
{

	// Find (n - 1) factorial
	int fac = 1;
	for (int i = 2; i <= n - 1; i++) {
		fac = fac * i;
	}

	// Return (n - 1)! * 2!
	return (fac * 2);
}

// Driver code
int main()
{
	int n = 5;

	cout << Total_Ways(n);

	return 0;
}
