/*
Given a string s, the task is to encrypt the string in the following way: 

If the frequency of current character is even, then increment current character by x.
If the frequency of current character is odd, then decrement current character by x.
Note: All the operations are circular that is adding 1 to ‘z’ will give ‘a’ and subtracting 1 from ‘a’ will give ‘z’
*/

// C++ implementation of the above approach:
#include <bits/stdc++.h>
#define MAX 26
using namespace std;

**
 * Recursive call.
 */
static String findEncryptedWord(String s) {
 
    // **** initialization ****
    String r    = "";
    int mid     = 0;
 
    // **** [0] compute the position of of middle character in S ****
    mid = s.length() / 2;
    if (s.length() % 2 == 0)
        mid -= 1;
 
    // **** [1] append the middle character of S ****
    r += s.substring(mid, mid + 1);
    /*
    A substring is a part of a string. A function to obtain 
    a substring in C++ is substr(). This function contains two parameters: pos and len. The pos parameter specifies the start position of the substring and len denotes the number of characters in a substring.
  */
 
    // **** [2] append the encrypted version of the substring of S 
    //      that's to the LEFT of the middle character (if non-empty) ****
    if (mid > 0) {
 
        // **** generate left sub string ****
        String ls = s.substring(0, mid);
 
        // **** encrypt and append ***
        r += findEncryptedWord(ls);
    }
 
    // **** [3] append the encrypted version of the substring of S 
    //      that's to the RIGHT of the middle character (if non-empty) ****
    if (mid < s.length() - 1) {
 
        // **** generate right sub string ****
        String rs = s.substring(mid + 1, s.length());
 
        // **** encrypt and append ****
        r += findEncryptedWord(rs);;
    }
 
    // **** return encrypted string ****
    return r;
}


// Function to return the encrypted string
string encryptStr(string str, int n, int x)
{
	
	// Reduce x because rotation of
	// length 26 is unnecessary
	x = x % MAX;
	
	// Calculate the frequency of characters
	int freq[MAX] = {0};
	
	for(int i = 0; i < n; i++)
	{
		freq[str[i] - 'a']++;
	}
	
	for(int i = 0; i < n; i++)
	{
		
		// If the frequency of current character
		// is even then increment it by x
		if (freq[str[i] - 'a'] % 2 == 0)
		{
			int pos = (str[i] - 'a' + x) % MAX;
			str[i] = (char)(pos + 'a');
		}
		
		// Else decrement it by x
		else
		{
			int pos = (str[i] - 'a' - x);
			
			if (pos < 0)
			{
				pos += MAX;
			}
			
			str[i] = (char)(pos + 'a');
		}
	}
	
	// Return the count
	return str;
}

// Driver code
int main()
{
	string s = "abcda";
	int n = s.size();
	int x = 3;
	
	cout << encryptStr(s, n, x) << endl;
	
	return 0;
}

// This code is contributed by avanitrachhadiya2155
import pytest

/*
def encrypt(string: str, start: int, end: int) -> list[str]:
    '''
    Encrypts the substring of `string` between indexes `start` and `end`,
    `substring = string[start:end + 1]`.

    O(n)
    '''
    # if starting index is greater than ending,
    # substring is an empty string,
    # len(substring) == 0
    if start > end:
        return []
    
    # if indexes are equal,
    # substring is just character at start index,
    # len(substring) == 1
    if start == end:
        return [string[start]]

    # encrypted string is list of strings to act as string builder
    encrypted = []
    # midpoint of substring
    midpoint = ((end - start) // 2) + start
    encrypted.append(string[midpoint])

    # append encrypted left substring
    encrypted.extend(encrypt(string, start, midpoint - 1))
    # append encrypted right substring
    encrypted.extend(encrypt(string, midpoint + 1, end))

    return encrypted

    */