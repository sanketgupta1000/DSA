// Problem Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pii;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //necessary DS
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> minDist(V);
        vector<bool> vis(V, false);
        
        //initializing
        pq.push({0, S});
        
        //now traversing
        while(!(pq.empty()))
        {
            pii edge = pq.top();
            pq.pop();
            
            int wt_tillnow = edge.first;
            int node = edge.second;
            
            if(!vis[node])
            {
                vis[node] = true;
                minDist[node] = wt_tillnow;
                
                //now checking for its neighbours
                for(auto neigh: adj[node])
                {
                    //adding the unvisited neighbour in pq
                    if(!vis[neigh[0]])
                    {
                        pq.push({wt_tillnow+neigh[1], neigh[0]});
                    }
                }
            }
        }
        
        return minDist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends