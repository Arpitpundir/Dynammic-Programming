#include<bits/stdc++.h>
using namespace std;

int minCoin(vector<int> coin, int c){

  int l = coin.size();
  vector<int> dp;
  dp.resize(c+1, INT_MAX);
  dp[0] = 0;

  for(int i = 1; i <= c;i++){
    for(int j = 0;j < l;j++){
      if(coin[j] <= i){

        dp[i] = min(dp[i], 1+dp[i-coin[j]]);
        //cout<<i<<" "<<dp[i]<<endl;
      }
    }
  }
}

int main(){

  int n;
  cin>>n;
  vector<int> coin;
  
  for(int i = 0;i < n;i++){

    int temp;
    cin>>temp;
    coin.push_back(temp);
  }

  int total;
  cin>>total;
  minCoin(coin, total);
}