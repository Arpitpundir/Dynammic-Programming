#include<bits/stdc++.h>
using namespace std;
/*
int main(){
  int n, w;
  cin>>n>>w;
  vector<int> val;
  vector<int> wt;

  for(int i = 0;i < n;i++){

    int temp;
    cin>>temp;
    if(temp != -1){
        val.push_back(temp);
        wt.push_back(i+1);

    }
  }

  int l = val.size();

  vector<int> dp;
  dp.resize(w+1, 0);

  for(int i = 1; i <= w; i++){

    if(i >= wt[0])
    dp[i] = INT_MAX;

    for(int j = 0;j < l; j++){

      if(wt[j] <= i){
        
        dp[i] = min(dp[i], val[j] + dp[i - wt[j]]);
        cout<<i<<" "<<j<<" "<<dp[i]<<endl;
      }
    }
  }

  cout<<dp[w];
}
*/

int main() {
    int n,w;
    cin>>n>>w;
    int value[w+1]; //correction -> size should be w+1 instead of n
    for(int i=1;i<=w;i++) // correction -> loop till w
    {
        cin>>value[i];
    }
    int dp[w+1];
    dp[0] = 0;
for(int i=1; i<=w; i++) // correction -> initialize all elements of dp array with value array elements
  {
    dp[i] = value[i];
  }
    for(int j=2;j<=w;j++)
    {  // int temp = value[j-1];
        for(int k=0;k<j;k++)
        {
           // if(temp==-1 && dp[k]!=-1 && dp[j-k]!=-1 )
                 // temp = dp[k]+dp[j-k];
           // else if(temp!=-1 && dp[k]!=-1 && dp[j-k]!=-1 ) temp = min(temp,dp[k]+dp[j-k]);     
              
             // cout<<j<<" "<<temp<<endl;
			  if(value[j-k] == -1  || dp[k] == -1){
				continue;
			  }
				if(dp[j] == -1)
				dp[j] = dp[k] + value[j-k];
				else
				dp[j] = min(dp[j], dp[k] + value[j-k]);

                cout<<j<<" "<<k<<" "<<dp[j]<<endl;

          }
         // dp[j] = temp;//cout<<dp[j]<<endl;
        }
        cout<<dp[w]<<endl;
    }
    