class Solution {
public: 
    int mod = pow(10,9)+7;
    int Comb(int n, int k , vector<vector<int>>&memo)
    {
        if(k==0) return 1;
        if(n==0) return 0;
        
        if(memo[n][k] != 0) return memo[n][k];
        
        memo[n][k] = Comb(n-1,k,memo) + Comb(n-1, k-1, memo);
        memo[n][k] %= mod;
        return memo[n][k];
    }
    
    int idealArrays(int n, int maxValue) {
        
        vector<vector<int>>dp(15,vector<int>(maxValue+1,-1));
        vector<vector<int>>memo(n+1,vector<int>(15,0));
        
        long long ans = 0;
        
        for(int i =1 ; i<=maxValue ; i++)
        {
            ans += helper(n, maxValue, 1, i, dp,memo)%mod;
        }
        return ans%mod;
    }
    
    int helper(int n, int maxValue ,int indx,int val, vector<vector<int>>&dp , vector<vector<int>>&memo)
    {

        if(indx == n) return 1;
        
        long long j =2;
        
        if(dp[indx][val] != -1) return dp[indx][val];
        
        long long ans = 0;
        
        bool flag =0;
        while(val*j <= maxValue)
        {
           ans += helper(n, maxValue, indx+1 , val*j,dp,memo)%mod;
            j++;
            
            if(val*j > maxValue)
                ans+= Comb(n-1,indx-1,memo)%mod;
            flag =1;
        }
        
        if(flag == 0)
        {
            if(val*j > maxValue)
                ans+= Comb(n-1, indx-1, memo)%mod;
        }
        
        return dp[indx][val] = ans%mod;
    }
};