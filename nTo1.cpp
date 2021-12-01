#include<bits/stdc++.h>
using namespace std;

int countStepsTo1(int n){
    
    if(n == 1){
        
        return 0;
    }else if(n == 2 || n == 3){
        
        return 1;
    }
    
    vector<int> ans;
    
    ans.push_back(0);
    ans.push_back(0);
    ans.push_back(1);
    ans.push_back(1);
    
    for(int i = 4; i <= n;i++){
        
        int temp1 = i%2 == 0?ans[i/2]:INT_MAX;
        int temp2 = i%3 == 0?ans[i/3]:INT_MAX;
        
        ans.push_back(1+min(ans[i-1], min(temp1, temp2)));
      }
    
    return ans[n];
}

int main(){

  int n;
  cin>>n;
  cout<<countStepsTo1(n)<<endl;
}