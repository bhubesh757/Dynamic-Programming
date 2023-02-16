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
    
