//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int MinCoin(vector<int> nums, int amount) {
        int n = nums.size();
        vector<vector<int>> t(n+1, vector<int>(amount+1));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (i == 0) {
                    t[i][j] = INT_MAX - 1;
                }
                else if (j == 0) {
                    t[i][j] = 0;
                }
                else if (i == 1) {
                    if (j % nums[0] != 0) {
                        t[i][j] = INT_MAX - 1;
                    } else {
                        t[i][j] = j / nums[0];
                    }
                }
                else if (nums[i - 1] <= j) {
                    t[i][j] = min(t[i - 1][j], 1 + t[i][j - nums[i - 1]]);
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        
        return (t[n][amount] == INT_MAX - 1 ) ? -1 : t[n][amount];
    }
};






//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends