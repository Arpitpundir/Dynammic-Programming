#include<bits/stdc++.h>
using namespace std;

int dpSoln(string s){
  int n = s.size();
  map<char, int> lastInd;
  vector<int> unqSub;
  unqSub.push_back(1);
  for(int i = 1; i <= n; i++){
    if(lastInd.count(s[i-1])){
      unqSub.push_back(2*unqSub[i-1]-unqSub[lastInd[s[i-1]]-1]);
    }else{
      unqSub.push_back(2*unqSub[i-1]);
    }
    lastInd[s[i-1]] = i;

    //cout<<unqSub[i]<<endl;
  }
  return unqSub[n];
}

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    cout<<dpSoln(s)<<endl;
  }
}