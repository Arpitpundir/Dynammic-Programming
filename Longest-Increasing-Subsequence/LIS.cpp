class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        int l = nums.size();
        
        if(l == 1 || l == 0){
            return l;
        }
        vector<int> dp;
        dp.resize(l, 1);
        int ans = INT_MIN;
        
        for(int i = 1; i < l;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i] && dp[i] < dp[j]+1){
                    
                    dp[i] = dp[j]+1;
                }
                if(ans < dp[i]){
                        
                    ans = dp[i];
                }
            }
        }
        return ans;
    }
};