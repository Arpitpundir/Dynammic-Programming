#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int LCSLen(string a, string b){
  int len1 = a.size(), len2 = b.size();
  vector<vector<int> > dp;
  dp.resize(len1+1,(vector<int>(len2+1,0)));

  for(int i=1;i<=len1;i++){
    for(int j=1;j<=len2;j++){
      if(a[i-1]==b[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
      }else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }

  return dp[len1][len2];
}

int main(){
  string s1,s2;
  cout<<"Enter String::";
  cin>>s1;
  for(int i=s1.size()-1;i>=0;i--) s2.push_back(s1[i]);
  cout<<LCSLen(s1,s2);
}