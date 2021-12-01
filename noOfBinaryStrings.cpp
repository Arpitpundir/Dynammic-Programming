#include<bits/stdc++.h>
using namespace std;

long int dpSoln(int n){
  long int n1 = 1;
  long int n2 = 2;
  for(int i = 2;i <= n;i++){
    long int temp1 = n1;
    long int temp2 = n2;
    n2 = temp1+temp2;
    n1 = temp2;
  }
  return n2;
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