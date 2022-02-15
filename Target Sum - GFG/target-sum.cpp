// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int subsetSumDiff(vector<int>arr, int sum){
        int n = arr.size();
        long long dp[n+1][sum+1];
        for(int i =0;i<n+1;i++){
            for(int j =0;j<sum+1;j++){
                if(i== 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }
        
        for(int i =1;i<n+1;i++){
            for(int j =0;j<sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>&nums ,int target) {
        int arrSum = 0;
        if(nums.size() == 0) return 0;
        for(int i =0;i<nums.size();i++)
            arrSum+= nums[i];
       if(arrSum < abs(target) || (target+arrSum) %2 != 0) return 0;
        int sum = (target + arrSum)/2;
        return subsetSumDiff(nums, sum);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends