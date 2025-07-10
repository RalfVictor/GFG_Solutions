// User function Template for C++

class Solution {
  public:
    void coins(vector<int>& curr,int i,int money,vector<int>& ans){
        if(money==0){
            return;
        }
        if(curr[i]<=money){
            ans.push_back(curr[i]);
            coins(curr,i,money-curr[i],ans);
        }else{
            coins(curr,i-1,money,ans);
        }
        return;
    }
    vector<int> minPartition(int N) {
        
        vector<int> curr = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        for(int i=9;i>=0;i--){
            if(N>=curr[i]){
                ans.push_back(curr[i]);
                coins(curr,i,N-curr[i],ans);
                break;
            }
        }
        return ans;
    }
};