//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void DFS(unordered_map<int,vector<int>>& adj,int u,vector<bool> &visited,vector<int>& result){
        if(visited[u]) return;
        visited[u]=true;
        result.push_back(u);
        
        for(int i=0;i<adj[u].size();i++){
            if(!visited[adj[u][i]]){
                DFS(adj,adj[u][i],visited,result);
            }    
        }
        
        return;
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        // Code here
        unordered_map<int,vector<int>> adj;
        for(int u=0;u<V;u++){
            for(int i=0;i<mp[u].size();i++){
                adj[u].push_back(mp[u][i]);
            }
        }
        
        vector<int> result;
        vector<bool> visited(V,false);
        
        DFS(adj,0,visited,result);
        
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
