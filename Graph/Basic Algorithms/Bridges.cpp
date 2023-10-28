//Problem Link: https://leetcode.com/problems/critical-connections-in-a-network/

//Solution:

class Solution {
private:
    void dfs(int node, int parent, int step, vector<vector<int>>&adj, vector<vector<int>>&bridges, vector<bool>&vis, int time[], int ltime[])
    {
        //marking as visited
        vis[node] = true;

        //time and lowest time
        time[node] = ltime[node] = step;

        //checking its neighbours
        for(auto neigh: adj[node])
        {
            if(!vis[neigh])
            {
                //do the dfs of its unvisited neighbours
                dfs(neigh, node, step+1, adj, bridges, vis, time, ltime);
            }

            //updating the ltime of node
            if(neigh!=parent)
            {
                ltime[node] = min(ltime[node], ltime[neigh]);
            }
        }

        //checking if node and parent can be a bridge
        if(ltime[node]>time[parent])
        {
            bridges.push_back({node, parent});
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        //tarjan's algorithm

        //getting the adjacency list
        vector<vector<int>> adj(n, vector<int>{});
        for(int i = 0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        //necessary DS
        //to store time and lowest time
        int time[n], ltime[n];
        //to store bridges
        vector<vector<int>> bridges;
        //visited array
        vector<bool> vis(n, false);

        //calling dfs
        dfs(0, 0, 1, adj, bridges, vis, time, ltime);

        return bridges;
    }
};