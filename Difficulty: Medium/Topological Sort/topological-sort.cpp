class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& ed) {
        vector<int> arr(V,0);
        vector<int> ans;
        vector<vector<int>> adj(V);
        for(auto it:ed){
            adj[it[0]].push_back(it[1]);
            arr[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(arr[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                arr[it]--;
                if(arr[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};