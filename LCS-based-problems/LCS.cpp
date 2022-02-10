#include <bits/stdc++.h>

using namespace std;

int LcsRecursive(string a, string b, int indA, int indB){
    if(indA<0||indB<0) return 0;
    if(a[indA]==b[indB]) return 1+LcsRecursive(a,b,indA-1,indB-1);
    else return max(LcsRecursive(a,b,indA-1, indB), LcsRecursive(a,b,indA, indB-1));
}

vector<vector<int> > memo;
int LcsMemo(string a, string b, int lenA, int lenB){
    if(lenA<=0||lenB<=0) return 0;
    else if(memo[lenA][lenB]!=-1) return memo[lenA][lenB];
    else if(a[lenA-1]==b[lenB-1]) return 1+LcsMemo(a,b,lenA-1,lenB-1);
    else return memo[lenA][lenB] = max(LcsMemo(a,b,lenA-1,lenB),LcsMemo(a,b,lenA,lenB-1));
}

int LcsDP(string a, string b){
    int lenA=a.size(),lenB=b.size();
    vector<vector<int> > dp;
    dp.resize(lenA+1,vector<int>(lenB+1,0));
    
    for(int row=1;row<=lenA;row++){
        for(int col=1;col<=lenB;col++){
            if(a[row-1]==b[col-1]){
                dp[row][col]=dp[row-1][col-1]+1;
            }else{
                dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
            }
        }
    }
    return dp[lenA][lenB];
}

int main()
{
    string a,b;
    cout<<"Enter input string:: ";
    cin>>a>>b;
    cout<<LcsRecursive(a,b,a.size()-1,b.size()-1);

    memo.resize(1001,vector<int>(1001,-1));
    for(int i=0;i<=1000;i++) memo[0][i] = 0;
    for(int i=1;i<=1000;i++) memo[i][0] = 0;
    cout<<"Enter input string:: ";
    cin>>a>>b;
    cout<<LcsMemo(a,b,a.size(),b.size());
    return 0;
}