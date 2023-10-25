//Problem link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // recursive function to find the dfs
    void dfs(int node, vector<int> adj[], vector<bool>&vis, vector<int>&ans)
    {
        //marking and adding in ans
        vis[node] = true;
        ans.push_back(node);
        
        //now checking for its unvisited neighbours
        for(auto neigh: adj[node])
        {
            if(!vis[neigh])
            {
                //do the dfs from the unvisited neighbour
                dfs(neigh, adj, vis, ans);
            }
        }
    }
  
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int start = 0;
        
        //visited array
        vector<bool>vis(V, false);
        
        //ans array
        vector<int> ans;
        
        //calling dfs
        dfs(start, adj, vis, ans);
        
        return ans;
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