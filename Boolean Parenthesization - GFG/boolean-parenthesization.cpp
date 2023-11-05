//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1003;
    
    int helper(string S, int i, int j, bool istrue, int*** output) {
        if (i > j) {
            return 0;
        }
        
        if (output[i][j][istrue] != -1) {
            return output[i][j][istrue];
        }
        
        if (i == j) {
            if (istrue) {
                return (S[i] == 'T') ? 1 : 0;
            } else {
                return (S[i] == 'F') ? 1 : 0;
            }
        }
        
        int ans = 0;
        
        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = helper(S, i, k - 1, true, output);
            int leftFalse = helper(S, i, k - 1, false, output);
            int rightTrue = helper(S, k + 1, j, true, output);
            int rightFalse = helper(S, k + 1, j, false, output);
            
            if (S[k] == '&') {
                if (istrue) {
                    ans += (leftTrue * rightTrue) % mod;
                } else {
                    ans += (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod + (leftFalse * rightFalse) % mod;
                }
            } else if (S[k] == '|') {
                if (istrue) {
                    ans += (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod;
                } else {
                    ans += (leftFalse * rightFalse) % mod;
                }
            } else if (S[k] == '^') {
                if (istrue) {
                    ans += (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod;
                } else {
                    ans += (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod;
                }
            }
        }
        
        output[i][j][istrue] = ans % mod;
        return output[i][j][istrue];
    }
    
    int countWays(int N, string S) {
        int i = 0;
        int j = N - 1;
        bool istrue = true;
        int*** output = new int**[N];
        for (int i = 0; i < N; i++) {
            output[i] = new int*[N];
            for (int j = 0; j < N; j++) {
                output[i][j] = new int[2];
                for (int k = 0; k < 2; k++) {
                    output[i][j][k] = -1;
                }
            }
        }
        int result = helper(S, i, j, istrue, output);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                delete[] output[i][j];
            }
            delete[] output[i];
        }
        delete[] output;
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends