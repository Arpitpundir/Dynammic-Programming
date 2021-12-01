#include<bits/stdc++.h>
using namespace std;

int find(vector<pair<int, int> > mat){
  int l = mat.size();
  vector<vector<int> > dp;
  dp.resize(l);

  for(int i = 0;i < l;i++){
    for(int j = 0;j < l;j++){

      dp[i].push_back(0);
    }
  }

  for(int i = 0;i < l-1;i++){
    dp[i][i+1] = mat[i].first*mat[i].second*mat[i+1].second;
  }

  for(int i = 2;i < l;i++){
    for(int j = 0;j+i < l; j++){

      dp[j][i+j] = INT_MAX;
      for(int k = 0;k < i; k++){

        dp[j][j+i] = min(dp[j][j+i], dp[j][j+k] + dp[j+k+1][i+j] + mat[j].first*mat[j+k].second*mat[j+i].second);
      }
    }
  }

  for(int i = 0;i < l;i++){
    cout<<endl;
    for(int j = 0;j < l;j++){
      cout<<dp[i][j]<<" ";
    }
  }

  return dp[0][l-1];
}

int main(){

  vector<pair<int, int> > mat;
  vector<int> dim;
  int n;
  cin>>n;

  for(int i = 0;i < n;i++){

    int temp;
    cin>>temp;
    dim.push_back(temp);
  }

  for(int i = 0; i < n-1;i++){
    mat.push_back(make_pair(dim[i], dim[i+1]));
  }

  cout<<find(mat);
}