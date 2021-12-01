n = int(input())
cost = []
cost.append(0)
for i in range(n):
  cost.append(int(input()))
  
dp = [cost[i] for i in range(0, n+1)]

def maxRodCuttingDp():
  for i in range(1, n+1):
    for j in range(1, i):
      dp[i] = max(dp[i], dp[j]+dp[i-j]) 
      
  return dp[n]

print(maxRodCuttingDp())

    