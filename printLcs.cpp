def printLcs(str1, str2):
    n = len(str1)
    m = len(str2)
    dp = [[0 for i in range (0, m+1)] for i in range(0, n+1)]

    for i in range(1, n+1):
        for j in range(1, m+1):
            if(str1[i-1] == str2[j-1]):
                dp[i][j] = dp[i-1][j-1]+1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    lcs = []
    i = n
    j = m
    while(i > 0 and j > 0):
        if(str1[i-1] == str2[j-1]):
            lcs.append(str1[i-1])
            i-=1
            j-=1
        elif(dp[i-1][j] > dp[i][j-1]):
            i-=1
        else:
            j-=1
    lcs = lcs[::-1]
    print("".join(lcs))

str1 = input()
str2 = input()
printLcs(str1, str2)