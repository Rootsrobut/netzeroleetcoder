//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(int n, int k, vector<vector<int>>& output) {
        if (n == 1) {
            return k;
        }
        if (k == 0 || k == 1) {
            return k;
        }
        if (output[n][k] != -1) {
            return output[n][k];
        }
        int ans = INT_MAX;
        for (int f = 1; f <= k; f++) {
            int tempans = 1 + max(solve(n - 1, f - 1, output), solve(n, k - f, output));
            ans = min(ans, tempans);
        }
        output[n][k] = ans;
        return ans;
    }

    int eggDrop(int n, int k) {
        vector<vector<int>> output(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, output);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends