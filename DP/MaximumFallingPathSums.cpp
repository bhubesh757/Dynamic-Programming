#include <bits/stdc++.h> 
//creating a function 
int f(int i , int j , vector<vector<int>> & matrix) {
if( i <  0 || j>= matrix[0].size()) return -1e8;
if(i == 0 ) return matrix[0][j];

//checking the matrixes

int mid = matrix[i][j] + f(i-1 , j , matrix) ;
int leftdiag = matrix[i][j] + f(i-1 , j-1 , matrix) ;
int rightdiag = matrix[i][j] + f(i-1 , j+1 , matrix);

// call the max funciton over it

return  max(mid , max(leftdiag ,rightdiag ));

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int maxi = -1e8;
    //calling the funtion throughoutthe top to end
    for(int j = 0 ; j < m ; j++) {
        maxi = max(maxi , f(n-1 , j , matrix));
    }
    return maxi;
    }


//Memoization

#include <bits/stdc++.h> 
//creating a function 
int f(int i , int j , vector<vector<int>> & matrix ,vector<vector<int>> & dp  ) {
if( i <  0 || j>= matrix[0].size()) return -1e8;
if(i == 0 ) return matrix[0][j];

//checking the matrixes
if(dp[i][j] != -1 ) return dp[i][j];
int mid = matrix[i][j] + f(i-1 , j , matrix ,dp) ;
int leftdiag = matrix[i][j] + f(i-1 , j-1 , matrix, dp) ;
int rightdiag = matrix[i][j] + f(i-1 , j+1 , matrix ,dp);

// call the max funciton over it

return dp[i][j] =   max(mid , max(leftdiag ,rightdiag ));

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    //memoization
    vector<vector<int>> dp(n , vector<int>(m , -1));
    int maxi = -1e8;
    //calling the funtion throughoutthe top to end
    for(int j = 0 ; j < m ; j++) {
        maxi = max(maxi , f(n-1 , j , matrix ,dp ));
    }
    return maxi;
    }
    

// Tabulation method 
class Solution {

//     int f(int i , int j , vector<vector<int>> & matrix) {
//       if( i <  0 || j>= matrix[0].size()) return -1e8;
//         if(i == 0 ) return matrix[0][j];

// //checking the matrixes

// int mid = matrix[i][j] + f(i-1 , j , matrix) ;
// int leftdiag = matrix[i][j] + f(i-1 , j-1 , matrix) ;
// int rightdiag = matrix[i][j] + f(i-1 , j+1 , matrix);

// // call the max funciton over it

// return  min(mid , max(leftdiag ,rightdiag ));

// }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //tabulation
        vector<vector<int>> dp(n , vector<int>(m , -1));

        for(int j = 0 ; j < m ;j++) {
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1 ; i < n ;i++) {
                for(int j = 0; j < m ;j++) {
                    int mid = matrix[i][j] + dp[i-1][j]; 
                    int leftdiag = matrix[i][j] ;
                    if(j-1 >=0)
                    leftdiag += 
                    dp[i-1][j-1];
                    else 
                    leftdiag += 10005; 
                    int rightdiag = matrix[i][j]; 
                    if(j+1<m) 
                    rightdiag += 
                    dp[i-1][j+1];
                    else 
                    rightdiag = 10005;  

                    dp[i][j] = min(mid , min(leftdiag , rightdiag));
                }
        }

    
        int mini = 10005;
    //calling the funtion throughoutthe top to end
        for(int j = 0 ; j < m ; j++) {
            mini = min(mini , dp[n-1][j]);
        }
        return mini;
    }
};

    
