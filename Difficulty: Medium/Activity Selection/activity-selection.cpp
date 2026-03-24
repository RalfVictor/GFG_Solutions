class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int,int>> temp;
        int n = start.size();
        for(int i=0;i<n;i++){
            temp.push_back({finish[i],start[i]});
        }
        sort(temp.begin(),temp.end());
        int ans = 1;
        int last = temp[0].first;
        for(int i=1;i<n;i++){
            if(temp[i].second>last){
                ans++;
                last = temp[i].first;
            }
        }
        return ans;
    }
};