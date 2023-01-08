class Solution {
public:
	int sum(int i,vector<int>& nums){
	int n = nums.size();
   long long int prev = nums[0];
   long long int prev2 = 0;
    
    for(int i=1 ; i < n ; i++) {
        //take andd not take
        long long int take = nums[i];
        if(n>1) take += prev2; 
        long long int notTake = 0+ prev;
        
         long long int curi = max(take , notTake);
        //poiting to other
        prev2 = prev;
        prev = curi;
    }
    return prev;
	}

	int rob(vector<int>& valueInHouse) {
		int n=valueInHouse.size();
		if(n==1)return valueInHouse[0];
		vector<int>t1,t2,dp1(n-1),dp2(n-1);
		for(int i=0;i<n;i++){
			if(i!=0)t1.push_back(valueInHouse[i]);
			if(i!=n-1)t2.push_back(valueInHouse[i]);
		}
		return max(sum(n-2,t1),sum(n-2,t2)); 
	}
};


