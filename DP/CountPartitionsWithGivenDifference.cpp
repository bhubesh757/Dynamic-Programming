//Memoization
#include <bits/stdc++.h> 
// as pe r the question they mentioned that it should be in 1e9 + 7
int mod = (int)(1e9 +7);
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
   return (take + notTake) % mod;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    //caling the function
    return f(n-1 , tar , num);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(auto &it : arr) totalSum += it;
    if( totalSum - d < 0 || (totalSum - d) % 2) return false;
    return findWays(arr, (totalSum - d) / 2);
}
// time limit exceeded time complexity :  O(n*n) 


