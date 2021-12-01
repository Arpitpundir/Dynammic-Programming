import math
n = int(input())
m = int(input())
cost = []


for i in range(n):
  row = []
  for j in range(m):
    temp = int(input())
    row.append(temp)
  cost.append(row)
    
for i in range(n):
  print(cost[i])


def gridRecursion(i, j):
  if(i == n-1 and j == m-1):
    return cost[i][j]
  if(i >= n or j >= n):
    return math.inf  
  ans = cost[i][j]+min(gridRecursion(i+1, j), gridRecursion(i, j+1))
  return ans

memo = [[-1 for i in range(m)] for i in range(n)]

def gridRecursionMemo(i, j):
  if(i == n-1 and j == m-1):
    return cost[i][j]
  if(i >= n or j >= m):
    return math.inf
  if(memo[i][j] != -1):
    return memo[i][j]
  ans = cost[i][j] + min(gridRecursionMemo(i+1, j), gridRecursionMemo(i, j+1))
  memo[i][j] = ans
  return ans

dp = [[0 for i in range(m)] for i in range(n)]

def gridRecursionDp():
  dp[0][0] = cost[0][0]
  for i in range(1,n):
    dp[0][i] = dp[0][i-1] + cost[0][i]
    
  for i in range(1, m):
    dp[i][0] = dp[i-1][0] + cost[i][0]
    
  for i in range(1, n):
    for j in range(1, m):
      dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1])
  return dp[n-1][n-1]
      
      

print(gridRecursion(0,0))
print(gridRecursionMemo(0, 0))
print(gridRecursionDp())
