#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > memo;

int MCM(vector<int> arr, int st, int end){
    if(end-st<=1) return 0;
    
    int ans = INT_MAX;
    for(int k=st+1;k<end;k++){
        int tempAns = MCM(arr,st,k)+MCM(arr,k,end)+arr[st]*arr[k]*arr[end];
        ans = min(ans,tempAns);
    }
    return ans;
}

int MCMMemo(vector<int> arr, int st, int end){
    
    if(end-st<=1) return 0;
    if(memo[st][end]!=-1) return memo[st][end]; 
    
    int ans = INT_MAX;
    for(int k=st+1;k<end;k++){
        int tempAns = MCM(arr,st,k)+MCM(arr,k,end)+arr[st]*arr[k]*arr[end];
        ans = min(ans,tempAns);
    }
    
    memo[st][end] = ans;
    return ans;
}

int main()
{
    memo.resize(1001,vector<int>(1001,-1));
    vector<int> arr;
    int n;
    cout<<"Enter number of elements::";
    cin>>n;
    while(n--){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    cout<<MCMMemo(arr, 0, arr.size()-1);
    return 0;
}