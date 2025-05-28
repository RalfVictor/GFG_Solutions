// User function Template for C++

class Solution {
  public:
    int f(vector<int>& price,int ind,int cap,vector<vector<int>>& dp){
        if(ind==0){
            if(cap>=1)
            return price[ind]*cap;
            return 0;
        }
        if(dp[ind][cap]!=-1) return dp[ind][cap];
        int notpick = f(price,ind-1,cap,dp);
        int pick = -1e9;
        if(ind+1<=cap){
            pick = price[ind]+f(price,ind,cap-(ind+1),dp);
        }
        return dp[ind][cap] = max(pick,notpick);
        
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(price,n-1,n,dp);
    }
};