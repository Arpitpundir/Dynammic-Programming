class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<pair<int,int> > dp;
        int maxLen=1,ans=1;
        dp.resize(n,{1,1});
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(dp[i].first<dp[j].first+1){
												
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }else if(dp[i].first==dp[j].first+1){
                        dp[i].second+=dp[j].second;
                    }
                }
            }
            if(maxLen<dp[i].first){
                    maxLen=dp[i].first;
                    ans=dp[i].second;
                }else if(maxLen==dp[i].first){
                    ans+=dp[i].second;
                }
        }
        for(int i=0;i<n;i++)
            cout<<dp[i].first<<" "<<dp[i].second<<endl;
        return ans;
    }
};