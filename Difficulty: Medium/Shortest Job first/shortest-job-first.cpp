// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        int n = bt.size();
        int add = 0;
        int fin = 0;
        for(int i=0;i<n-1;i++){
            add += bt[i];
            fin += add;
        }
        return fin/n;
    }
};