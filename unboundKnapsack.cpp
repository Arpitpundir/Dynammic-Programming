#include<bits/stdc++.h>
using namespace std;

int dpSoln(int capacity, vector<int> weight, vector<int> val){
    vector<int> dp;
    dp.resize(capacity+1);
    dp[0] = 0;
    int n = weight.size();
    for(int i = 1;i < capacity+1;i++){
        for(int j = 0; j < n;j++){
            if(i >= weight[j]){
                int temp = val[j]+dp[i-weight[j]];
                if(temp > dp[i]){
                    dp[i] = temp;
                }
            }
        }
    }
    return dp[capacity];
}
int main(){
    int capacity;
    int n;
    cin>>n>>capacity;
    vector<int> weight, val;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        weight.push_back(temp);
    }
    for(int i = 0; i < n;i++){
        int temp;
        cin>>temp;
        val.push_back(temp);
    }
    cout<<dpSoln(capacity, weight, val)<<endl;
}
