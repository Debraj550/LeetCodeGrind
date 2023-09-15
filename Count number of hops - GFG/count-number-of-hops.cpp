//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    int mod = 1000000007;
    vector<int> dp;
    long long solve(int target, int currentStep) {
        if(currentStep > target) return 0;
        if(currentStep == target) return 1;
        if(dp[currentStep]!=-1) return dp[currentStep];
        
        long long stepOne = solve(target, currentStep + 1)%mod;
        long long stepTwo = solve(target, currentStep + 2)%mod;
        long long stepThree = solve(target, currentStep + 3)%mod;
        
        return dp[currentStep] = (stepOne + stepTwo + stepThree) % mod;
    }
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        dp.resize(n+1, -1);
        return solve(n, 0);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends