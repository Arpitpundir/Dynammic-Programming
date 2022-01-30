#include<bits/stdc++.h>
using namespace std;
int UnboundedKnapsack(int W, vector<int> weights, vector<int> values){
  int n = weights.size();
  vector<vector<int> > subProb(n+1, vector<int> (W+1));
  for(int i=0;i<=n;i++){
    subProb[i][0] = 1;
  }

  for(int i=1;i<=W;i++){
    subProb[0][i] = 0;
  }

  for(int )
}
int main(){
  int capacity = 8;
  vector<int> val = {10, 40, 50, 70}, weights = {1,3,4,5};
  cout<<"Max Profit that we can make when infinite instances are there for each item is: "<<UnboundedKnapsack()
}