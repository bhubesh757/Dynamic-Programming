class Solution {
    public :
    bool f(int  n , vector<int> &stones , vector<int> &dp , int k) {
        //assign the values
        dp[0] = 0;
        //loop trought the i;
        for(int i = 1 ; i <=n;i++) {
            int minstep = INT_MAX;

            for(int j = 1 ; j<= k ; j++) {
                //initialize the jump
                if(i-j >= 0){

                int jump = dp[i-j] + abs(stones[i] - stones[i-j]);
                int minstep = min(minstep , jump);
                }
                //store them
            }
        dp[i] = minstep;
        }
        //getting the last element as  the answer 
        return  dp[n-1] = 0;
    }

public:
    bool canCross(vector<int>& stones) {
    int n ;
    int  k;
    vector<int> dp(n,-1);
    return f(n, stones, dp, k) ;
        
    }
};
