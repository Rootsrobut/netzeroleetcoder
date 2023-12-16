//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), comp); 
        int ans = 1;
        int firstend = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > firstend) {
                ans++;
                firstend = v[i].second;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends