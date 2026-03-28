class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        vector<int> vis(V,0);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if(vis[node]==1) continue;
            vis[node] = 1;
            ans = ans+w;
            for(auto t:adj[node]){
                    int noden = t.first;
                    int nw = t.second;
                    if(vis[noden]==0) pq.push({nw,noden});
            }
        }
        return ans;
    }
};