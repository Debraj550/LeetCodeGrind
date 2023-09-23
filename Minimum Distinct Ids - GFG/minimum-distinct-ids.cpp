//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int distinctIds(int arr[], int n, int m)
    {
        // Complete this function
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        
    
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        while(!pq.empty() && m) {
            int topCount = pq.top().first;
            int topEle = pq.top().second;
            if(topCount <= m) {
                m -= topCount;
            }
            else if(topCount > m) break;
            pq.pop();
        }
        return pq.size();
        
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
          cin>>arr[i];
        }
    
    	int m ;
    	cin >> m;
        Solution ob;
    	cout << ob.distinctIds(arr, n, m) << endl;
    }
	return 0;
}
// } Driver Code Ends