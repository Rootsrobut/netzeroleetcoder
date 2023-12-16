//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K) {
    vector<int> v;
    sort(candies, candies + N);
    int byeIndex = 0;
    int freeIndex = N - 1;
    int minByeCost = 0;
    while (byeIndex <= freeIndex) {
        minByeCost += candies[byeIndex];
        byeIndex++;
        freeIndex =freeIndex - K;
    }
    byeIndex = N - 1;
    freeIndex = 0;
    int maxByeCost = 0;
    while (byeIndex >= freeIndex) {
        maxByeCost += candies[byeIndex];
        byeIndex--;
        freeIndex =freeIndex + K;
    }
    v.push_back(minByeCost);
    v.push_back(maxByeCost);

    return v;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends