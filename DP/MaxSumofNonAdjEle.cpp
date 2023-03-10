//Wrote By Bhubesh SR
//Using Recursion
#include <bits/stdc++.h> 


//creating a function
int f(int ind , vector<int> &nums) {
    if(ind == 0) return nums[ind];
    if(ind < 0 ) return 0;
    
   int  pick = nums[ind] + f(ind-2 , nums);
    int nonpick = 0 + f(ind-1 , nums);
    
    return max(pick , nonpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return f(n-1 , nums);
}

--------
// Using Memoization
  
  
  #include <bits/stdc++.h> 


//creating a function
int f(int ind , vector<int> &nums , vector<int> &dp) {
    if(ind == 0) return nums[ind];
    if(ind < 0 ) return 0;
    if(dp[ind] != -1) return dp[ind];
    
   int  pick = nums[ind] + f(ind-2 , nums ,dp);
    int nonpick = 0 + f(ind-1 , nums ,dp);
    
    dp[ind] =  max(pick , nonpick);
    return dp[ind];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
  //must initialize its as n , -1
    vector<int> dp(n,-1);
    return f(n-1 , nums , dp);
}

----------
  //tabulation
  
  //Space Optimization
    #include <bits/stdc++.h> 


//creating a function
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
   int prev = nums[0];
    int prev2 = 0;
    
    for(int i=1 ; i < n ; i++) {
        //take andd not take
        int take = nums[i];
        if(n>1) take += prev2; 
        int notTake = 0+ prev;
        
        int curi = max(take , notTake);
        //poiting to other
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
