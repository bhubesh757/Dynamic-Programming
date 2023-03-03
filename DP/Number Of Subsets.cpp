#include <bits/stdc++.h> 
//create a function

int f(int ind , int sum , vector<int> &num) {
    if(sum == 0 ) return 1;
    if(ind == 0 ) return num[0] == sum;

   int notTake = f(ind -1 , sum , num);
   int take = 0;

   if(num[ind] <= sum) {
       take = f(ind - 1 , sum - num[ind] , num);
   }
   return take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    //caling the function
    return f(n-1 , tar , num);
}



// Memoization
#include <bits/stdc++.h> 
//create a function

int f(int ind , int sum , vector<int> &num ,vector<vector<int>> &dp) {
    
    if(sum == 0 ) return 1;
    if(ind == 0 ) return num[0] == sum;

    if(dp[ind][sum] != -1) return dp[ind][sum];
    
   int notTake = f(ind -1 , sum , num , dp);
   int take = 0;

   if(num[ind] <= sum) {
       take = f(ind - 1 , sum - num[ind] , num , dp);
   }
   return dp[ind][sum] =  take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n , vector<int>(tar+1 , -1));
    //caling the function
    return f(n-1 , tar , num , dp);
}

//
tabulation

#include <bits/stdc++.h> 
//create a function

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n , vector<int>(tar+1 , 0));
    //convert the -1 to 0 for tabulation
    //base cases
    for(int i = 0 ; i < n ; i++) dp[i][0] = 1;
    if(num[0] <= tar) {
        dp[0][num[0]] = 1; 
    }

    for(int ind = 1 ; ind < n ; ind++) {
        for(int sum = 0 ; sum <= tar ; sum++) {
            //paste the recursion part over here
            int notTake = dp[ind -1][sum];
            int take = 0;

   if(num[ind] <= sum) {
       take = dp[ind - 1][sum- num[ind]];
   }
    dp[ind][sum] =  take + notTake;
        }
    }
    return dp[n-1][tar];
}

//space optimization

#include <bits/stdc++.h> 
//create a function

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1 , 0) , curr(tar+1);
    //convert the -1 to 0 for tabulation
    //base cases
    prev[0] = curr[0] = 1;
    if(num[0] <= tar) {
        prev[num[0]] = 1; 
    }

    for(int ind = 1 ; ind < n ; ind++) {
        for(int sum = 0 ; sum <= tar ; sum++) {
            //paste the recursion part over here
            int notTake = prev[sum];
            int take = 0;

   if(num[ind] <= sum) {
       take = prev[sum- num[ind]];
   }
    curr[sum] =  take + notTake;
        }
        prev = curr;
    }
    return prev[tar];
}


// modifies test cases which doesnt match the other test cases 
int f(int ind , int sum , vector<int> &num) {
    if(ind == 0) {
        if(sum == 0 &&  num[0] == 0 ) return 2;
        if(sum == 0 || sum == num[0]) return 1;
        return 0;
    }

   int notTake = f(ind -1 , sum , num);
   int take = 0;

   if(num[ind] <= sum) {
       take = f(ind - 1 , sum - num[ind] , num);
   }
   return take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    //caling the function
    return f(n-1 , tar , num);
}

