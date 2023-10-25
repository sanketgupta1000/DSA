//Problem Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        //iterative approach
        
        //necessary data structures
        vector <bool> vis(V, false);
        vector <int> ans;
        stack <int> stk;
        vector <int> index(V, 0);
        
        int start = 0;
        
        //initialization
        vis[start] = true;
        ans.push_back(start);
        stk.push(start);
        
        //traversing the graph
        while(!(stk.empty()))
        {
            int node = stk.top();
            
            bool isAnyUnvisited = false;
            
            //checking for its unvisited neighbours
            
            vector<int>&neigh = adj[node];
            while(index[node]<neigh.size())
            {
                if(!vis[neigh[index[node]]])
                {
                    
                    isAnyUnvisited = true;
                    
                    //marking it as visited, adding in array, pushing in stack
                    vis[neigh[index[node]]] = true;
                    ans.push_back(neigh[index[node]]);
                    stk.push(neigh[index[node]]);
                    
                    //incrementing index so that next time, next neighbour is checked
                    index[node]++;
                    
                    //breaking so that dfs from the unvisited neighbour can be done
                    break;
                }
                
                //incrementing index so that next time, next neighbour is checked
                index[node]++;
            }
            
            if(!isAnyUnvisited)
            {
                stk.pop();
            }
        }
        
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