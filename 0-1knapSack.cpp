#include<bits/stdc++.h>
using namespace std;

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
int recursiveSoln(vector<int> weights, vector<int> value, int totQty, int n, int currInd){
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