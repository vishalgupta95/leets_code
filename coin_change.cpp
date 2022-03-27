// coin change
#include <iostream>
#include <vector>
using namespace std;
/*
his is a practice problem from Facebook's recruiting portal:

You likely know that different currencies have coins and bills of different denominations. In some currencies, it's actually impossible to receive change for a given amount of money. For example, Canada has given up the 1-cent penny. If you're owed 94 cents in Canada, a shopkeeper will graciously supply you with 95 cents instead since there exists a 5-cent coin.
Given a list of the available denominations, determine if it's possible to receive exact change for an amount of money targetMoney. Both the denominations and target amount will be given in generic units of that currency.

Signature
boolean canGetExactChange(int targetMoney, int[] denominations)

Input
1 ≤ |denominations| ≤ 100
1 ≤ denominations[i] ≤ 10,000
1 ≤ targetMoney ≤ 1,000,000

Output
Return true if it's possible to receive exactly targetMoney given the available denominations, and false if not.

Example 1
denominations = [5, 10, 25, 100, 200]
targetMoney = 94
output = false
Every denomination is a multiple of 5, so you can't receive exactly 94 units of money in this currency.

Example 2
denominations = [4, 17, 29]
targetMoney = 75
output = true
You can make 75 units with the denominations [17, 29, 29].
*/




 boolean canGetExactChange(int targetMoney, int[] denominations) {
     if(targetMoney < 0)
       return false;
    if(targetMoney == 0)
      return true;
    for(int i = 0; i < denominations.length;i++){
      if(canGetExactChange(targetMoney - denominations[i], denominations)){
        return true;
      }
    }
    return false;
    
  }






/*
Input: S = { 1, 3, 5, 7 }, target = 8
 
The total number of ways is 6
 
{ 1, 7 }
{ 3, 5 }
{ 1, 1, 3, 3 }
{ 1, 1, 1, 5 }
{ 1, 1, 1, 1, 1, 3 }
{ 1, 1, 1, 1, 1, 1, 1, 1 }
 
 
Input: S = { 1, 2, 3 }, target = 4
 
The total number of ways is 4
 
{ 1, 3 }
{ 2, 2 }
{ 1, 1, 2 }
{ 1, 1, 1, 1 }
The idea is to use recursion to solve this problem. We 
recur to see if the total can be reached by choosing the coin or not for each coin of given denominations. If choosing the current coin results in the solution, update the total number of ways.

*/


#include <iostream>
#include <vector>
using namespace std;
 
// Function to find the total number of distinct ways to get a change of `target`
// from an unlimited supply of coins in set `S`
int count(vector<int> const &S, int n, int target)
{
    // if the total is 0, return 1 (solution found)
    if (target == 0) {
        return 1;
    }
 
    // return 0 (solution does not exist) if total becomes negative,
    // no elements are left
    if (target < 0 || n < 0) {
        return 0;
    }
 
    // Case 1. Include current coin `S[n]` in solution and recur
    // with remaining change `target-S[n]` with the same number of coins
    int include = count(S, n, target - S[n]);
 
    // Case 2. Exclude current coin `S[n]` from solution and recur
    // for remaining coins `n-1`
    int exclude = count(S, n - 1, target);
 
    // return total ways by including or excluding current coin
    return include + exclude;
}
 
// Coin Change Problem
int main()
{
    // `n` coins of given denominations
    vector<int> S = { 1, 2, 3 };
    int n = S.size();
 
    // total change required
    int target = 4;
 
    cout << "The total number of ways to get the desired change is "
         << count(S, n - 1, target);
 
    return 0;
 
// Coin Change Problem
int main()
{
    // `n` coins of given denominations
    vector<int> S = { 1, 2, 3 };
 
    // total change required
    int target = 4;
 
    cout << "The total number of ways to get the desired change is "
         << count(S, target);
 
    return 0;