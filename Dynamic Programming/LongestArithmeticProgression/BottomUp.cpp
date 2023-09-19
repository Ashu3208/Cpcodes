int lengthOfLongestAP(int A[], int n) {
        if(n<=2){
            return n;
        }
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(10000,1));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
               int diff = A[i]-A[j];
               int cnt=1;
               if(dp[j][diff]) cnt=dp[j][diff];
               dp[i][diff]=1+cnt;
               ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
