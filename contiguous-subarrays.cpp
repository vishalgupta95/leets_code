/* Count contiguous subarrays
ou are given an array arr of N integers. For each index i, you are required to determine the number of contiguous subarrays that fulfill the following conditions:
The value at index i must be the maximum element in the contiguous subarrays, and
These contiguous subarrays must either start from or end on index i.
Signature
int[] countSubarrays(int[] arr)
Input
Array arr is a non-empty list of unique integers that range between 1 to 1,000,000,000
Size N is between 1 and 1,000,000
Output
An array where each index i contains an integer denoting the maximum number of contiguous subarrays of arr[i]
Example:
arr = [3, 4, 1, 6, 2]
output = [1, 3, 1, 5, 1]
*/

vector CountSubarrays(vector arr)
{
    vector dp(arr.size());

    if (dp.size() == 0 || dp.size() == 1)
    {
        return dp;
    }
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++)
    {
        int curr = arr[i];
        int count = 1;
        int left = i - 1;
        int right = i + 1;
        while (left >= 0)
        {
            if (arr[left] < curr)
            {
                ++count;
            }
            else
            {
                left = 0;
            }
            left--;
        }
        while (right < dp.size())
        {
            if (arr[right] < curr)
            {
                ++count;
            }
            else
            {
                right = dp.size();
            }
            right++;
        }
        dp[i] = count;
    }
    return dp;
}

