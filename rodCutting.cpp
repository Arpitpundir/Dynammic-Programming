#include<bits/stdc++.h>
using namespace std;

class data{
  public:
  int i;
  int j;
  int k;
  data(int val1, int val2, int val3){
    this->i = val1;
    this->j = val2;
    this->k = val3;
  }
};

vector<int> find(vector<long int > points, long int n){
  class data{
  public:
  long int i;
  long int j;
  long int k;
  data(long int val1, long int val2, long int val3){
    this->i = val1;
    this->j = val2;
    this->k = val3;
  }
};
    
points.push_back(n);
  points.push_back(0);

  sort(points.begin(), points.end());

  long int l = points.size();

  vector<vector<pair<int, int> > > dp;
  dp.resize(l+2);
  for(long int i = 0;i < l; i++){
    for(long int j = 0;j < l; j++){
      dp[i].push_back(make_pair(0, -1));
    }
  }

  for(long int i = 2;i < l; i++){
    //cout<<"i "<<i<<endl;
    for(long int j = 0;j+i < l;j++){
  //    cout<<" j "<<j<<endl;
      dp[j][j+i].first = INT_MAX;
      for(long int k = 1;k < i; k++){
//cout<<"  k "<<k<<endl;
        long int temp = points[j+i] - points[j]+dp[j][j+k].first + dp[j+k][j+i].first;
        if(temp < dp[j][i+j].first){

          dp[j][i+j].first = temp;
          dp[j][i+j].second = j+k;
        }
      //  cout<<"   "<<j<<" "<<j+i<<" "<<dp[j][j+i].first<<" "<<dp[j][j+i].second<<endl;
      }
    }
  }

  data *newNode = new data(0, l-1, dp[0][l-1].second);
  stack<data*> q;
  q.push(newNode);
  vector<int> ans;

  while(!q.empty()){
    data *temp = q.top();
    q.pop();

    ans.push_back(points[temp->k]);

   // cout<<ans[ans.size()-1]<<endl;

    //cout<<temp->i<<" "<<temp->k<<" "<<temp->j<<endl;

   if(dp[temp->k][temp->j].second != -1){
      data *newNode = new data(temp->k, temp->j, dp[temp->k][temp->j].second);
      q.push(newNode);
    }
    if(dp[temp->i][temp->k].second != -1){
      data *newNode = new data(temp->i, temp->k, dp[temp->i][temp->k].second);
      q.push(newNode);
    }
  }

  return ans;
}

long int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  vector<int> points;

  for(int i = 0;i < m;i++){

    int temp;
    cin>>temp;
    points.push_back(temp);
  }

  find(points, n);

}