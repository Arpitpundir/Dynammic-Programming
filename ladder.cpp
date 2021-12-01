#include<bits/stdc++.h>
using namespace std;

long long int mod = pow(10, 9)+7;

int main(){
  int t, n;
  cin>>t>>n;
  while(t--){
    
    int target, k;
    cin>>target>>k;

    vector<int> dp;
    dp.resize(target+1, 0);
    dp[0] = 1;

    for(int i = 1; i < target+1; i++){

      if(i >= 2){

        dp[i] += (dp[i-2])%mod;
      }

      if(i >= 5){

        dp[i] += dp[i-5]%mod;
      }

      if(i >= k){

        dp[i] += dp[i-k]%mod;
      }
    }

    cout<<dp[target]<<endl;
  }
}