class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        queue<int> q;
        vector<int> ans(V,1e9);
        ans[src] = 0;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& i:adj[node]){
                if(ans[node]+1<ans[i]){
                    ans[i] = ans[node]+1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(ans[i]==1e9){
                ans[i]= -1;
            }
        }
        return ans;
    }
};
