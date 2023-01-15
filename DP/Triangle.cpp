

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

