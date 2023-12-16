//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long, vector<long long>, greater<long long>> mp;
       for(int i=0;i<n;i++){
           mp.push(arr[i]);
       }
       long long  cost=0;
       while(mp.size()>1){
       long long a=mp.top();
       mp.pop();
       long long b=mp.top();
       mp.pop();
       cost=cost+(a+b);
       mp.push(a+b);
       }
       return cost;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends