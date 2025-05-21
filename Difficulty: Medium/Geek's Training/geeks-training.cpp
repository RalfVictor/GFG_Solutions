class Solution {
  public:
    int funct(vector<vector<int>>& dp,vector<vector<int>>& arr,int day,int last){
        if(day==0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi = max(maxi,arr[0][i]);
                }
            }
        return maxi;       
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(last!=i){
            int today = arr[day][i]+funct(dp,arr,day-1,i);
            maxi = max(maxi,today);
        }
    }
    return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
       int day = arr.size();
       vector<vector<int>> dp(day,vector<int>(4,-1));
       return funct(dp,arr,day-1,3);
    }
};