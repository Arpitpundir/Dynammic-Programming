class Solution{
    int modu = 1003;
vector<vector< pair<int,int> > > memo;

pair<int, int> solve(int st, int end, string A){
    if(end-st==0){
        if(A[st] == 'T') {
            memo[st][end] = {1,0};
            return {1,0};
        }
        else {
            memo[st][end] = {0,1};
            return {0,1};
        }
    }
    if(memo[st][end].first !=0 || memo[st][end].second!=0) return memo[st][end];
    int tNum = 0, fNum = 0;
    for(int k=st+1;k<end;k+=2){
        pair<int, int> left = solve(st,k-1,A), right = solve(k+1,end,A);
        int T, F;
        switch(A[k]){
            case '|':
            T = (left.first*right.first+left.first*right.second+left.second*right.first)%modu;
            F = (left.second*right.second)%modu;
            break;
            case '&':
            T = (left.first*right.first)%modu;
            F = (left.first*right.second+left.second*right.first+left.second*right.second)%modu;
            break;
            case '^':
            T = (left.first*right.second+left.second*right.first)%modu;
            F = (left.first*right.first+left.second*right.second)%modu;
            break;
        }
        tNum = (tNum+T)%modu;
        fNum = (fNum+F)%modu;
    }
    memo[st][end] = {tNum,fNum};
    return {tNum,fNum};
}
public:
    int countWays(int N, string A){
        memo.resize(A.size(),vector<pair<int,int> >(A.size(),make_pair(0,0)));
        solve(0, A.size()-1, A);
        return memo[0][A.size()-1].first;
    }
};