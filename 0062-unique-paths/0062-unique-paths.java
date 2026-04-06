class Solution {
    static int[][]dirs={{0,1},{1,0}};
    public int uniquePaths(int m, int n) {
        int[][]dp=new int[m][n];
        for(int i=0;i<m;i++)Arrays.fill(dp[i],-1);
        return f(0,0,m,n,dp);
        
    }
    private int f(int r,int c,int m,int n,int[][]dp){
        if(r==m||c==n)return 0;
        if(r==m-1&&c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=0;
        for(int[]dir:dirs){
           ans+=f(r+dir[0],c+dir[1],m,n,dp);
        }
        return dp[r][c]=ans;
    }
}