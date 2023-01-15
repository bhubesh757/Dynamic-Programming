

class Solution {
    public:
    int f(int i , int j , vector<vector<int>> &a , int n) {
        //base case
        if(i == n-1) return a[n-1][j];
        //else
        int down = a[i][j] + f(i+1 , j , a ,n);
        int diagonal = a[i][j] + f(i+1 , j+1 ,a,n);
        return min(down , diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //base case
       int n = triangle.size();
        int m = triangle.size();
        return f(0 , 0 , triangle , n);
    }
};

-----------Tabulation
class Solution {
    // public:
    // int f(int i , int j , vector<vector<int>> &a , int n , vector<vector<int>> &dp) {
    //     //base case
    //     if(i == n-1) return a[n-1][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     //else
    //     int down = a[i][j] + f(i+1 , j , a ,n , dp);
    //     int diagonal = a[i][j] + f(i+1 , j+1 ,a,n , dp);
    //     return dp[i][j] =  min(down , diagonal);
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //base case
        //only n because of nx n size
       int n = triangle.size();
        // int m = triangle.size();
        vector<vector<int>> dp(n , vector<int> (n, 0));

        for(int j = 0 ; j<n ; j++) dp[n-1][j] = triangle[n-1][j];
        for(int i = n-2 ; i >=0 ; i--) {
            for(int j = i ; j>=0 ; j-- ){
                //recursion part
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
             dp[i][j] =  min(down , diagonal);
            }
        }
        return dp[0][0];
    }
};
