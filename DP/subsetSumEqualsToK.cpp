#include <bits/stdc++.h> 

//create a function

bool f(int ind , int target ,vector<int> &arr ) {
    //base cases
    if(target == 0 ) return true;
    if(ind == 0 ) return arr[0] == target;

    //take and not take 
    bool notTake = f(ind-1 , target , arr);
    bool take = false;

    if(target >= arr[ind]) {
        take = f(ind-1 , target - arr[ind] , arr);
    }
    return take | notTake;

}


bool subsetSumToK(int n, int k, vector<int> &arr) {
   //just rerturn the values

   return f(n-1 , k , arr);
}



//Memoization 

#include <bits/stdc++.h> 

//create a function

bool f(int ind , int target ,vector<int> &arr , vector<vector<int>>& dp ) {
    //base cases
    if(target == 0 ) return true;
    if(ind == 0 ) return arr[0] == target;

    if (dp[ind][target] != -1 ) return dp[ind][target];
    //take and not take 
    bool notTake = f(ind-1 , target , arr ,dp);
    bool take = false;

    if(target >= arr[ind]) {
        take = f(ind-1 , target - arr[ind] , arr ,dp);
    }
    return dp[ind][target] =  take | notTake;

}


bool subsetSumToK(int n, int k, vector<int> &arr) {
   //just rerturn the values
   vector<vector<int>> dp(n , vector<int> (k+1 , -1));
   return f(n-1 , k , arr , dp);
}

//Tabulaion

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
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
    
    return dp[n-1][k];
}


//space optimization
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    vector<bool> prev(k+1 , 0) , curr(k+1 , 0);
    prev[0] = true ;
    curr[0] = true;
    
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTake = prev[target];
    
            bool take = false;
                if(target>= arr[ind])
                    take = prev[target-arr[ind]];
        
            curr[target]= notTake||take;
        }
        prev = curr;
    }
    
    return prev[k];
}
