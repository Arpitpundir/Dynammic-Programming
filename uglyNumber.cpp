#include<bits/stdc++.h>
using namespace std;
int dpSoln(int n){
  int curr = 0, ind2 = 1, ind3 = 1, ind5 = 1;
  for(int i = 0;i < n-1; i++){
    curr = min(2*ind2, min(3*ind3, 5*ind5));

    if(curr%2 == 0){
      ind2++;
    }
    if(curr%3 == 0){
      ind3++;
    }
    if(curr%5 == 0){
      ind5++;
    }
    cout<<curr<<endl;
  }
  return curr;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<dpSoln(n)<<endl;
  }
}