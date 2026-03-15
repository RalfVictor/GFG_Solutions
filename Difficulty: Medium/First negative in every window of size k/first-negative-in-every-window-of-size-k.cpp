class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        vector<int> ans;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<0) q.push(i);
            while(!q.empty() && i-q.front()==k) q.pop();
            if(i>=k-1){
                if(q.empty()) ans.push_back(0);
                else ans.push_back(arr[q.front()]);
            }
        }
        return ans;
    }
};