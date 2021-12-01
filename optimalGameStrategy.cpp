#include<bits/stdc++.h>
using namespace std;

int dpSoln(vector<int> coins){
  int n = coins.size();
  vector<vector<int> > dp;
  dp.resize(n);
  for(int i = 0;i < n;i++){
    dp[i].resize(n);
  }

  for(int i = 0; i < n;i++){
    dp[i][i] = coins[i];
  }

  for(int i = 0; i < n-1;i++){
    dp[i][i+1] = max(coins[i], coins[i+1]);
  }

  for(int k = 2; k < n;k++){
    for(int i = 0;i < n-k;i++){
      int j = i+k;
        dp[i][j] = max(coins[i]+min(dp[i+2][j], dp[i+1][j-1]), coins[j] + min(dp[i+1][j-1], dp[i][j-2]));
    }
  }

  return dp[0][n-1];
}

int main(){
  int n;
  cin>>n;

  vector<int> coins;
  for(int i = 0;i < n;i++){
    int temp;
    cin>>temp;
    coins.push_back(temp);
  }
  cout<<dpSoln(coins)<<endl;
}
