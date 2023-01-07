//recursion to memoization method and recursion to memoization to tabulation i.e bottom top approach

#include <bits/stdc++.h> 
// anow use dynamic programming

int f(int ind , vector<int> &heights ,vector<int> &dp ) {
    if(ind == 0) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    
    int left = f(ind - 1 , heights ,dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    
    if(ind > 1 ) 
         right = f(ind - 2 , heights , dp) + abs(heights[ind] - heights[ind - 2]); 
    
    //now store them in dp array
    return dp[ind] =  min(left , right);
}

int frogJump(int n, vector<int> &heights )
{
    //calling the function
    vector<int> dp(n+1 , -1);
    return f(n-1 , heights  , dp);
}

-----------
 
  //Tabulation
  
  #include <bits/stdc++.h> 


int frogJump(int n, vector<int> &heights )
{
    //initialize them
    vector<int> dp(n , 0);
     dp[0] = 0;
    //loop them
    for(int i= 1 ; i < n;i++) {
     int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
     int ss = INT_MAX;
        
        if(i>1) 
            ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        //storing the min function in the dp array
        dp[i] =  min(fs , ss);
    }
    //returning the last element
    return dp[n-1];
    
    
}
