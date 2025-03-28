//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist(V,1e8);
        dist[0] = 0;
        for(int i=0;i<E-1;i++){
            for(int j=0;j<E;j++){
                int s = edges[j][0];
                int d = edges[j][1];
                int dis = edges[j][2];
                if(dist[s]+dis<dist[d]){
                    dist[d] = dist[s]+dis;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e8){
                dist[i]=-1;
            }
        }
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends