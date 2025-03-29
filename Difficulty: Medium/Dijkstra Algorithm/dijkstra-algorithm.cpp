//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        int n=adj.size();
        vector<int> distances(n,INT_MAX);
        distances[src]=0;
        while(!pq.empty()){
            pair<int,int> f=pq.top();
            pq.pop();
            int distance=f.first;
            int node=f.second;
            for(auto nbr:adj[node]){
                int new_distance=distance+nbr.second;
               if (new_distance < distances[nbr.first]) {  
                distances[nbr.first] = new_distance;
                pq.push({new_distance, nbr.first});
               }
            }
        }
        for(int i=0;i<n;i++){
            if(distances[i]==INT_MAX)
            distances[i]=-1;
        }
        return distances;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends