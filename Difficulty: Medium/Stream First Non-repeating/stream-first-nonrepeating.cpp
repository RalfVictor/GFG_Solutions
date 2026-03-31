class Solution {
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char,int> mp;
        string ans = "";
        queue<char> q;
        for(auto& i:s){
            mp[i]++;
            if(mp[i]==1) q.push(i);
            while(!q.empty()){
                if(mp[q.front()]==1) break;
                q.pop();
            }
            if(q.empty()) ans.push_back('#');
            else ans.push_back(q.front());
        }
        return ans;
    }
};