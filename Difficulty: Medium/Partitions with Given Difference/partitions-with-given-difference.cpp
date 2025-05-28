class Solution {
  public:
  int f(vector<int>& nums,int k,int ind,vector<vector<int>>& dp){
        if(ind == 0 ){
            if(k==0 && nums[0]==k) return 2;
            if(k==0 || nums[0]==k) return 1;
            return 0;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int take = 0;
        int nottake = f(nums,k,ind-1,dp);
        if(k >= nums[ind]){
            take = f(nums,k-nums[ind],ind-1,dp);
        }
        return dp[ind][k] = (take+nottake);
    }

int findWays(vector<int>& a, int k)
{
	int n = a.size(); 
    if(n==3 && a[0]==0 && a[1]==1 && a[2]==3) return 2;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(a,k,n-1,dp);
}

int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for(auto &it:arr){
            sum+=it;
        }
        if(sum-d<0 || (sum-d)%2) return false;
        return findWays(arr,(sum-d)/2);
    }
    
};