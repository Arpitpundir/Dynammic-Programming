class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int> > dp;
        dp.resize(len1+1, vector<int>(len2+1,0));
        int ans = 0;
        for(int row=1;row<=len1;row++){
            for(int col=1;col<=len2;col++){
                if(nums1[row-1]==nums2[col-1]){
                    dp[row][col] = 1+dp[row-1][col-1];
                    ans=max(ans,dp[row][col]);
                }else{
                    dp[row][col] = 0;
                }
            }
        }
        return ans;
        
    }
};