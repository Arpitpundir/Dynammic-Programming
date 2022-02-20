class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        vector<vector<bool> > isPal;
        isPal.resize(n, vector<bool> (n, false));
        vector<int> dp;
        dp.resize(n, 0);
        int count = 0;
        for(int i = 0;i < n;i++){
            
            isPal[i][i] = true;
            count++;
        }
        for(int i = 1;i < n;i++){
            for(int j = 0;j+i < n;j++)
                
                if(s[j] == s[i+j] && (i<2||isPal[j+1][i+j-1])){
                    //cout<<i<<" "<<j<<endl;
                    isPal[j][i+j] = true;
                    count++;
                }
            }
        return count;
        
    }
};