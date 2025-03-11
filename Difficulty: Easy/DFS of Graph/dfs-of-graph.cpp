//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int vertex,vector<vector<int>>& adj,vector<int> &visited,vector<int> &ls){
        visited[vertex]=1;
        ls.push_back(vertex);
        for(auto it: adj[vertex]){
            if(visited[it]) continue;
            dfs(it,adj,visited,ls);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int x=adj.size();
        vector<int> visited(x,0);
        visited[0]=1;
        vector<int> ls;
        dfs(0,adj,visited,ls);
        return ls;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends