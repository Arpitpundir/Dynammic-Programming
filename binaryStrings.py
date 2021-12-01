t = int(input())

def validBinStrings(n):
  if(n == 2):
      return [3, 2]
  else:
      temp = validBinStrings(n-1)
      return [temp[0]+temp[1], temp[0]]
  
def validBinStringsDp(N):
  n1 = 3
  n2 = 2
  for i in range(3, N+1):
    temp = n1
    n1 = n1+n2
    n2 = temp
  
  print(n1)
while(t != 0):
  N = int(input())
  t-=1
  validBinStringsDp(N)
  
  