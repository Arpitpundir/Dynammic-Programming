// Problem: given a number of items where each one of them a certain weight assigned to them and a bag with weight capacity w, find out if we can fill bag with a subset of given items 

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<bool> > subProb(n+1, vector<bool>(B+1));

    for(int i=0;i<=n;i++){
        subProb[i][0] = true;
    }
    for(int i=1;i<=B;i++){
        subProb[0][i]=false;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=B;j++){
            if(A[i-1]<=j){
                subProb[i][j] = subProb[i-1][j-A[i-1]]||subProb[i-1][j];
            }else{
                subProb[i][j] = subProb[i-1][j];
            }
        }
    }
    return subProb[n][B];
}