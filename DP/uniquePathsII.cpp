int mod = (int)(1e9+7);

int f(int i , int j , vector<vector<int>> &a) {
        //three base cases
        if(i >= 0 && j >= 0 && a[i][j] == -1 ) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0 ) return 0;
        int up = f(i-1 , j , a);
        int left = f(i,j-1 , a);

        return up + left;
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return f(n-1 , m-1 , mat);
}

