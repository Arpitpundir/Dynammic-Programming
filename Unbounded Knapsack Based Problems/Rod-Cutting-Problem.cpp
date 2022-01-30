class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
       int cutsNum = cuts.size();
        vector<vector<int> > dp;
        dp.resize(cutsNum, vector<int> (cutsNum, INT_MAX));
        
        for(int i=0;i<cutsNum-1;i++){ // mistake
            dp[i][i+1] = 0;
        }
        for(int i=0;i<cutsNum-2;i++){
            dp[i][i+2]=cuts[i+2]-cuts[i];
        }
        
        for(int gap=3;gap<cutsNum;gap++){
            for(int row=0;row+gap<cutsNum;row++){
                for(int col=row+1;col<row+gap;col++){
                    dp[row][row+gap] = min(dp[row][row+gap], cuts[row+gap]-cuts[row]+dp[row][col]+dp[col][row+gap]); //mistake
                }
            }
        }
        return dp[0][cutsNum-1];
    }
}; 