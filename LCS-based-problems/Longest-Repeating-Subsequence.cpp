#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str){
  int len = str.size();
  vector<vector<int> > dp;
  dp.resize(len+1, vector<int>(len+1,0));

  for(int row=1;row<=len;row++){
    for(int col=1;col<=len;col++){
      if(row!=col && str[row-1] == str[col-1]){
        dp[row][col] = dp[row-1][col-1]+1;
      }else{
        dp[row][col] = max(dp[row-1][col],dp[row][col-1]);
      }
    }
  }

  return dp[len][len];
}

int main(){
  string s;
  cout<<"Enter string::";
  cin>>s;

  cout<<LongestRepeatingSubsequence(s);
}