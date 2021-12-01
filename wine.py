n = int(input())
wineCost = []
for i in range(n):
  temp = int(input())
  wineCost.append(temp)
  
def maxCostRecursion(be, end, yr):
  if(be > end):
    return 0
  elif(be == end):
    return wineCost[be]*yr
  
  cost1 = wineCost[be]*yr+maxCostRecursion(be+1, end, yr+1)
  cost2 = wineCost[end]*yr+maxCostRecursion(be, end-1, yr+1)
  return max(cost1, cost2)

memo = [[-1 for i in range(0, n)] for i in range (0, n)]

def maxCostRecursionMemo(be, end , yr):
  if(be > end):
    return 0
  elif(be == end):
    memo[be][end] = wineCost[be]*yr
    return memo[be][end]
  cost1 = cost2 = 0
  if(memo[be+1][end]!=-1):
    cost1 = memo[be+1][end]+wineCost[be]*yr
  else:
    cost1 = wineCost[be]*yr+maxCostRecursionMemo(be+1, end, yr+1)
  
  if(memo[be][end-1]!=-1):
    cost2 = memo[be][end-1]+wineCost[end]*yr
  else:
    cost2 = wineCost[end]*yr+maxCostRecursionMemo(be, end-1, yr+1)
  
  return max(cost1, cost2)

dp = [[-1 for i in range(0, n)] for i in range(0, n)]

def maxCostRecursionDp():
  yr = n
  for k in range(0, n):
    for i in range(0, n):
      if(i+k >= n):
        break
      if(k == 0):
        dp[i][i] = yr*wineCost[i]
      else:
        dp[i][i+k] = max(wineCost[i]*yr + dp[i+1][i+k], wineCost[i+k]*yr + dp[i][i+k-1])
    yr-=1
    
  return(dp[0][n-1])

print(maxCostRecursion(0, n-1, 1))
print(maxCostRecursionMemo(0, n-1, 1))
print(maxCostRecursionDp())