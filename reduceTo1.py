import math
n = int(input())
dp = [-1]*(n+1)
dp[1] = 0
for i in range(2, n+1):
  step1 = 1+dp[i-1]
  step2 = 0
  if(i%2 == 0):
    step2 = 1+dp[int(i/2)]
  else:
    step2 = math.inf
  step3 = 0
  if(i%3 == 0):
    step3 = 1+dp[int(i/3)]
  else:
    step3 = math.inf
  dp[i] = min(step1, step2, step3)
print(dp[n])
