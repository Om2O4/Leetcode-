class Solution {
    private int n;
    private int[] sfx;
    private int[][] dp;

    private int solve(int i,int m){
        if(i==n){
            return 0;
        }
        else if(dp[i][m]!=-1){
            return dp[i][m];
        }
        int b=0;
        for(int x=1;x<=2*m && i+x <=n;x++){
            int nxt=Math.max(m,x);
            int curr = sfx[i]-solve(i+x,nxt);
            b=Math.max(b,curr);
        }
        return dp[i][m]=b;
    }

    public int stoneGameII(int[] piles) {
        n = piles.length;
        sfx=new int[n+1];
        for(int i=n-1;i>=0;i--){
            sfx[i]=sfx[i+1]+piles[i];
        }
        dp=new int[n][n+1];
        for(int i=0;i<n;i++){
            java.util.Arrays.fill(dp[i],-1);
        }
        return solve(0,1);
    }
}