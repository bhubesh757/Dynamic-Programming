#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;
	for(int i=0 ; i<n ; i++) totSum += arr[i];
	int k = totSum;

	vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
     if(arr[i] <= k)   dp[i][0] = true;
    }
    
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTake = dp[ind-1][target];
    
            bool take = false;
                if(target>= arr[ind])
                    take = dp[ind-1][target-arr[ind]];
            dp[ind][target]= notTake||take;
        }
    }

	//making the differencea and finding min among this
    int min_i = 1e9;
    for(int i = 0 ; i<= totSum ; i++) {
        if(dp[n-1][i] == true) {
            int diff = abs((totSum-i) - i) ;
            min_i = min(min_i , diff);
        }
    }
    return min_i;
    
}
