#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, t;
  cin>>n>>t;
  vector<int> val;

  for(int i = 0;i < n;i++){

    int temp;
    cin>>temp;
    val.push_back(temp);
  }

  vector<bool> dp;
  dp.resize(n+1, false);
  dp[0] = true;

  for(int i = 0; i < n;i++){
    for(int j = t; j >= 0; j--){

      if(val[i] <= j){

        dp[j] = dp[j - val[i]];
      }
    }
  }

  if(dp[t]){

    cout<<"Yes";
  }else{

    cout<<"No";
  }
}