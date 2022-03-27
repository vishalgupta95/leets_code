/*
Magical Candy Bags
You have N bags of candy. The ith bag contains arr[i] pieces of candy, and each of the bags is magical!
It takes you 1 minute to eat all of the pieces of candy in a bag (irrespective of how many pieces of candy are inside), and as soon as you finish, the bag mysteriously refills. If there were x pieces of candy in the bag at the beginning of the minute, then after you've finished you'll find that floor(x/2) pieces are now inside.
You have k minutes to eat as much candy as possible. How many pieces of candy can you eat?
Signature
int maxCandies(int[] arr, int K)
Input
1 ≤ N ≤ 10,000
1 ≤ k ≤ 10,000
1 ≤ arr[i] ≤ 1,000,000,000
Output
A single integer, the maximum number of candies you can eat in k minutes.
Example 1
N = 5 
k = 3
arr = [2, 1, 7, 4, 2]
output = 14

2,1,7,4,2
3
main <<< arr: [2, 1, 7, 4, 2]
main <<<   K: 3
main <<< output: 14
 
 
output = 14
The first line contains the numbers of candy pieces per magic bag. In our case we have five bags. The second line indicates the number of minutes we have to eat candy. In this case we have three minutes to consume as much candy as possible.

We can use a priority queue or heap. We keep the bag with most pieces on the top of the heap. At the start of each minute we consume all the candy and compute what will happen with that bag in the next minute. The rest of the bags are of no interest. When we put the updated bag in the heap it should re arrange the bags to keep the one with the most pieces on the top.
 The process repeats for as many minutes as we are required.
*/

/**
 * You have k minutes to eat as much candy as possible. 
 * How many pieces of candy can you eat?
 * O(n)
 */
static int maxCandies(int[] arr, int k) {
 
    // **** initialization ****
    int candies = 0;
    PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {
        public int compare (Integer i0, Integer i1) {
            if (i1 > i0)
                return 1;
            else if (i0 == i1)
                return 0;
            else
                return -1;
        }
    });
 
    // **** populate priority queue O(n)****
    for (int a : arr)
        pq.add(a);
     
    // **** loop eating candies O(k) ****
    for (int m = 0; m < k; m++) {
 
        // **** eat all candies from head bag ****
        int pieces = pq.remove();
 
        // **** count number of candies eaten ****
        candies += pieces;
 
        // **** compute pieces for next minute ****
        pieces = Math.floorDiv(pieces, 2);
 
        // **** add pieces for next minute ****
        pq.add(pieces);
    }
 
    // **** max number of candies ****
    return candies;
}

/*

void solve() {
    int n, k;
    cin >> n >> k;
    ll a;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        cin >> a, pq.push(a);
    ll count = 0;
    while (k--) {
        count += pq.top();
        pq.push(pq.top()/2);
        pq.pop();
    }
    cout << count << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

*/