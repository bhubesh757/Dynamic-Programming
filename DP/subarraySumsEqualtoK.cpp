class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int > mp;
        int count =0 ;
        int sum = 0;
        int n = nums.size();
        //traverse through the array and add them accordingly
        for(int i = 0 ; i<n ; i++) {
            sum = sum+ nums[i];

             if(sum == k ) {
            count++;
        }


        //where k is the target value
        //if the sum is found in in the any of the array size then just incerement the count
        if(mp.find(sum-k) != mp.end()) {
            count = mp[sum-k] + count;
        }

        //another condition 
        if(mp.find(sum) != mp.end()) {
            mp[sum]++;
        }
        else {
             mp[sum] = 1;
        }
        }
        
       

        return count;
       
    }

};
