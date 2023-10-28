// Problem link: https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  private:
    void dfs(int node, int parent, int step, vector<int>adj[], vector<bool>&vis, int time[], int ltime[], vector<bool>&isAP)
    {
        //mark it as visited
        vis[node] = true;
        
        //set time and lowest time
        time[node] = ltime[node] = step;
        
        //to check for root node in dfs tree
        int children = 0;
        
        //checking for its neighbours
        for(auto neigh: adj[node])
        {
            if(!vis[neigh])
            {
                //do the dfs of its unvisited neighbour
                dfs(neigh, node, step+1, adj, vis, time, ltime, isAP);
                
                children++;
                
                //updating ltime of node
                ltime[node] = min(ltime[node], ltime[neigh]);
                
                //checking if node can be an articulation point w.r.t. neigh
                if((parent!=-1)&&(ltime[neigh]>=time[node]))
                {
                    isAP[node] = true;
                }
            }
            else if(parent!=neigh)
            {
                //taking time of already visited neighbour
                ltime[node] = min(ltime[node], time[neigh]);
            }
        }
        
        //check for root of dfs tree
        if((parent==-1)&&(children>1))
        {
            isAP[node] = true;
        }
        
    }

  public:
    vector<int> articulationPoints(int V, vector<int>adj[])
    {
        //modified tarjan's algo
        
        //necessary DS
        vector<bool>vis(V, false);
        int time[V];
        int ltime[V];
        vector<bool>isAP(V, false);
        
        //calling dfs
        dfs(0, -1, 1, adj, vis, time, ltime, isAP);
        
        vector<int>ans;
        
        for(int i = 0; i<V; i++)
        {
            if(isAP[i])
            {
                ans.push_back(i);
            }
        }
        
        if(ans.size())
        {
            return ans;
        }
        else
        {
            return {-1};
        }
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends