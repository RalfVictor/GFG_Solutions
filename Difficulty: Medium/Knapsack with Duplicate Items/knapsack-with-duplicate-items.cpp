// User function Template for C++

class Solution {
  public:
  int f(vector<int>& val,vector<int>& wt,int ind, int cap,vector<vector<int>>& dp){
      if(ind==0){
          if(wt[ind]<=cap){
              return val[ind]*(cap/wt[ind]);
          }
          return 0;
      }
      if(dp[ind][cap]!=-1) return dp[ind][cap];
      int nottake = f(val,wt,ind-1,cap,dp);
      int take = INT_MIN;
      if(wt[ind]<=cap){
          take = val[ind] + f(val,wt,ind,cap-wt[ind],dp);
      }
      return dp[ind][cap] = max(take,nottake);
      
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return f(val,wt,n-1,capacity,dp);
    }
};