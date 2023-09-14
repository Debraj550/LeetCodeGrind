//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    vector<vector<int>> dp;
    bool solve(int arr[], int n, int idx, int target) {
        if(idx == n) {
            return target == 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int take = 0;
        if(arr[idx] <= target)
            take = solve(arr, n, idx+1, target - arr[idx]);
        int notTake = solve(arr, n, idx+1, target);
        return dp[idx][target] = take || notTake;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int tot = 0;
        for(int i = 0; i<N;i++){
            tot += arr[i];
        }
        if(tot%2) return 0;
        int target = tot/2;
        dp.resize(N+1, vector<int>(target+1, -1));
        if(solve(arr, N, 0, target)) return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends