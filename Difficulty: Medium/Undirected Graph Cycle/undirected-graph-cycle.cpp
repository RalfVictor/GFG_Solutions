//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool dfs(int node,int parent, vector<vector<int>>& adj,vector<int>& vis){
      vis[node] = 1;
      for(auto i:adj[node]){
          if(!vis[i]){
              if(dfs(i,node,adj,vis)==1){
                  return true;
              }
          }
          else if(i!=parent){
              return true;
          }
      }
      return false;
  }
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,-1,adj,vis)==1){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends