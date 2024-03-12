//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    int DFS(vector<int> adj[],int u,vector<bool> & visited,int parent){
        visited[u]=true;
        int res=0;
        for(int i=0;i<adj[u].size();i++){
            
            if(adj[u][i]==parent) continue;
            
            if(visited[adj[u][i]]){
                return 1;
            }
            
            if(DFS(adj,adj[u][i],visited,u)==1) return 1;
        }
        
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       vector<bool> visited(V,false);
       
       for(int i=0;i<V;i++){
           if(!visited[i]){
               int res=DFS(adj,i,visited,-1);
               if(res==1) return 1;
           }
       }
        
        return 0;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
