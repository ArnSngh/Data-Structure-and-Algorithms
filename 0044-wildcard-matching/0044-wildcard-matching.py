class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n=len(p)
        m=len(s)
        dp=[[None]*(m) for _ in range(n)]
        def dp_fn(i,j):
            if(i<0 and j>=0):
                return False
            if(i<0 and j<0):
                return True
            if(i>=0 and j<0):
                for x in range(i+1):
                    if(p[x]!='*'):
                        return False
                return True
            if dp[i][j] is not  None:
                return dp[i][j]            
            if(s[j]==p[i] or p[i]=='?'):
                dp[i][j]=dp_fn(i-1,j-1)
            elif(p[i]=='*'):
                dp[i][j]=dp_fn(i-1,j) or dp_fn(i,j-1)
            else:
                dp[i][j]=False
            return dp[i][j]
        return dp_fn(n-1,m-1)