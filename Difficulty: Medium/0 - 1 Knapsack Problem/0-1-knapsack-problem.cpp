class Solution {
  public:
    int f(vector<pair<int,int>>& temp,int i,vector<vector<int>>& dp,int n,int w){
        if(i==n) return (temp[i].first == w)?temp[i].second:0;
        if(w==0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        int nott = f(temp,i+1,dp,n,w);
        int take = 0;
        if(temp[i].first <= w)
        take = temp[i].second + f(temp,i+1,dp,n,w-temp[i].first);
        return dp[i][w] = max(nott,take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<pair<int,int>> temp;
        int n = val.size();
        for(int i=0;i<n;i++){
            temp.push_back({wt[i],val[i]});
        }
        sort(temp.begin(),temp.end());
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return f(temp,0,dp,n,W);
    }
};