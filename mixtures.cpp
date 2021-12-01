#include<bits/stdc++.h>
using namespace std;

long long int dpSoln(vector<int> colors){
  vector<vector<long long int> > dp;
  vector<vector<long long int> > sum;
  int n = colors.size();
  dp.resize(n);
  sum.resize(n);
  
  for(int i = 0;i < n;i++){
    dp[i].resize(n);
    sum[i].resize(n);
    sum[i][i] = colors[i];
  }

  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          dp[i][j]=10000000000000000;
      }
  }

  for(int i=0;i<n;i++){
      dp[i][i] = 0;
  }

  for(int k = 2; k <= n; k++){
    for(int i = 0;i <= n-k;i++){
      int j = i+k-1;
      for(int br = i; br < j; br++){

        //cout<<dp[i][j]<<endl;
        long long int tempSmoke = dp[i][br]+dp[br+1][j]+(sum[i][br]*sum[br+1][j]);
        if(tempSmoke < dp[i][j]){
          dp[i][j] = tempSmoke;
          sum[i][j] = (sum[i][br]+sum[br+1][j])%100;
        }
      }
      //cout<<dp[i][j]<<"jk"<<endl;
    }
  }
  return dp[0][n-1];
}

int main(){
  int n;
  cin>>n;
  vector<int> color;
  for(int i = 0; i < n;i++){
    int temp;
    cin>>temp;
    color.push_back(temp);
  }
printf("%llu\n",dpSoln(n));
}