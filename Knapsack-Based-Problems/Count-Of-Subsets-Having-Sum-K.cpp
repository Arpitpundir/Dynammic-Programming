#include <bits/stdc++.h>
using namespace std;
  
int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int subProb[n + 1][sum + 1];
  // Initializing the first value of matrix
    subProb[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        subProb[0][i] = 0;
    for (int i = 1; i <= n; i++)
        subProb[i][0] = 1;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum 
            if (a[i - 1] > j)
                subProb[i][j] = subProb[i - 1][j];
            else
            {
                subProb[i][j] = subProb[i - 1][j] + subProb[i - 1][j - a[i - 1]];
            }
        }
    }
  
  
    return subProb[n][sum];
}
  
int main()
{
    int n = 4;
    int a[] = {3,3,3,3};
    int sum = 6;
  
    cout << (subsetSum(a, n, sum));
}