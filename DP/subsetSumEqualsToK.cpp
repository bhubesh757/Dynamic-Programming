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
