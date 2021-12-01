#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int minJumpDp(vector<int> arr){
  int n = arr.size();
  vector<int> jump(n,1000000);
  jump[0] = 0;
  for(int i = 1;i < n;i++){
    for(int j = 0;j <= i;j++){
      if(arr[j]+j >= i){
        jump[i] = min(jump[j]+1, jump[i]);
      }
    }
  }
  return jump[n-1];
}
int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
  cin>>n;
  vector<int> arr;
  for(int i = 0;i < n;i++){
      int temp;
      cin>>temp;
      arr.push_back(temp);
  }
  cout<<minJumpDp(arr)<<endl;
  }
}
