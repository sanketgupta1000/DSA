//Problem link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, int> pii;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //Prim's Algo
        
        //necessary DS
        //priority queue of pair
        //by default, pq of pair sorts w.r.t. first of pair.
        //so, will keep edge weight in first, and node to be visited in second
        //also, greater<pii> for min heap
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> vis(V, false);
        
        pii temp;
        int minSum = 0;
        
        //initializing
        pq.push({0, 0});
        
        //now traversing
        while(!(pq.empty()))
        {
            temp = pq.top();
            pq.pop();
            
            if(!vis[temp.second])
            {
                //visiting the unvisisted
                vis[temp.second] = true;
                
                //adding in minSum
                minSum += temp.first;
                
                //now adding its unvisited neighbours in pq
                for(auto neigh: adj[temp.second])
                {
                    if(!vis[neigh[0]])
                    {
                        pq.push({neigh[1], neigh[0]});
                    }
                }
            }
        }
        
        return minSum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends