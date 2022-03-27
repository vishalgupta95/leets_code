
/*

We have N different apps with different user growth rates. At a given time t, measured in days, the number of users using an app is g^t (for simplicity we'll allow fractional users), where g is the growth rate for that app. These apps will all be launched at the same time and no user ever uses more than one of the apps. We want to know how many total users there are when you add together the number of users from each app.

After how many full days will we have 1 billion total users across the N apps?

Signature

int getBillionUsersDay(float[] growthRates)
 
Input

1.0 < growthRate < 2.0 for all growth rates
1 <= N <= 1,000

Output

Return the number of full days it will take before we have a total of 1 billion users across all N apps.

Example 1


growthRates = [1.5]
output = 52

Example 2


growthRates = [1.1, 1.2, 1.3]
output = 79

Example 3


growthRates = [1.01, 1.02]
output = 1047
Solution Summary O(n log (n)) time and O(1) space
Start is 1 and end is Max integer and target is 1 Billion
While start less than end.
Calculate the mid
Calculate the total users for that mid day.
If total is matching with target then return the mid day.
Else If total is more than the target then move end to mid-1
Else move start to mid+1

*/

long calculateGrowthRates(vector& growthRates, int day) {
  long numOfUsers = 0;
  for (auto rate: growthRates) 
    numOfUsers += pow(rate, day);
  return numOfUsers;
}

int getBillionUsersDay(vector growthRates) {
  int day = 1;
  int step = 1;
  while (calculateGrowthRates(growthRates, day + step) < BILLION) {
    day += step;
    step *= 2;
  }
  
  while (step != 0) {
    while (calculateGrowthRates(growthRates, day + step) < BILLION) 
      day += step;
    step /= 2;
  }
  
  return day + 1;
}