#include<bits/stdc++.h>
using namespace std;

// recursive soln
int recursiveSoln(vector<int> weights, vector<int> value, int totQty, int n, int currInd){
  if(currInd == n || totQty==0){
    return 0;
  }
  if(weights[currInd]>totQty){
    return recursiveSoln(weights, value, totQty, currInd++);
  }
  int profitAfterIncluding = recursiveSoln(weights, value, totQty - weight[currInd], currInd++)+value[currInd];
  int profiTAfterNotIncluding = recursiveSoln(weights, value, totQty, currInd++);
  return max(profitAfterIncluding, profitAfterNotIncluding);
} 

// memoized soln
vector<vector<int> > t;
int memoizedSoln(vector<int> weights, vector<int> value, int totQty, int n, int currInd){
  if(currInd == n || totQty==0){
    return 0;
  }
  if(weights[currInd]>totQty){
    return t[totQty][currInd] = recursiveSoln(weights, value, totQty, currInd++);
  }

  if(t[totQty][currInd] != -1){
    return t[totQty][currInd];
  }

  int profitAfterIncluding = recursiveSoln(weights, value, totQty - weight[currInd], currInd++)+value[currInd];
  int profiTAfterNotIncluding = recursiveSoln(weights, value, totQty, currInd++);
  return t[totQty][currInd] = max(profitAfterIncluding, profitAfterNotIncluding);
} 

// top-down soln
int topDownSoln(vector<int> weights, vector<int> value, int totQty, int n, int currInd){
  vector<vector<int> > t;
  t.resize(n+1, vector<int>(totQty+1));

  // initialization
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(i==0||j==0){
        t[i][j]=0;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      t[i][j] = t[i-1][j];
      if(weights[i]>=m){
        t[i][j] = max(t[i-1][j-weights[i]]+value[i], t[i-1][j]);
      }
    }
  }
  return t[n][totQty];
}