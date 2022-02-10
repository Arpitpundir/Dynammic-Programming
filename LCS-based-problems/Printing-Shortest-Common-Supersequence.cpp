void printScs(vector<vector<int> > dp, string a, string b){
    int row = dp.size()-1, col = dp[0].size()-1;
    vector<char> ans;
    while(row && col){
        if(a[row-1] == b[col-1]){
            ans.push_back(a[row-1]);
            row--, col--;
        }else if(dp[row-1][col]<dp[row][col-1]){
            ans.push_back(b[col-1]);
            col--;
        }else {
            ans.push_back(a[row-1]);
            row--;
        }
    }
    while(row){
        ans.push_back(a[row-1]);
        row--;
    }
    
    while(col){
        ans.push_back(b[col-1]);
        col--;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
}