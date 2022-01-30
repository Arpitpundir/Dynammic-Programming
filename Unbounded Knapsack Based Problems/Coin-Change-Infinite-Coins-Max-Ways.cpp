class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int coinNum=coins.size();
        vector<vector<int> > dp;
        dp.resize(coinNum+1,vector<int>(amount+1, 0));
        
        for(int row=0;row<=coinNum;row++){
            dp[row][0] = 1;
        }
        
        for(int col=1;col<=amount;col++){
            dp[0][col]=0;
        }
        
        for(int coinInd=0;coinInd<coinNum;coinInd++){
            for(int quant=1;quant<=amount;quant++){
                if(coins[coinInd]>quant) 
                    dp[coinInd+1][quant] = dp[coinInd][quant];
                else 
                dp[coinInd+1][quant] = dp[coinInd+1][quant-coins[coinInd]]+dp[coinInd][quant];
            }
        }
        
        return dp[coinNum][amount];
    }
};