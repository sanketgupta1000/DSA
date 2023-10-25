//Problem Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//Solution:
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // does not take into account disconnected components
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        //necessary data structures
        vector<bool> vis(V, false);
        vector<int> ans;
        queue<int> q;
        
        int start = 0;
        
        //initialization
        vis[start] = true;
        q.push(start);
        
        //now traversing the graph
        while(!(q.empty()))
        {
            int node = q.front();
            q.pop();
            //adding in ans
            ans.push_back(node);
            
            //now checking for its neighbours
            for(auto neigh: adj[node])
            {
                if(!vis[neigh])
                {
                    //marking unvisited neighbour and adding in queue
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        
        //returning
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends