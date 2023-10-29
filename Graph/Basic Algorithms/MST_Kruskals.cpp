//Problem Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//Solution:

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int,int> pii;
typedef pair<int, pii> pip;

//Kruskal's Algo, with union by rank

//implementation of disjoint set, with union by size

class DisjointSet
{
private:
    //array to store parents
    int * const parent;
    //array to store sizes
    int * const size;
    //size of ds
    int sz;

    //utility function to find ultimate parent of a node
    int UltP(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        else
        {
            //path compression
            return (parent[node] = UltP(parent[node]));
        }
    }

public:
    //constructor
    DisjointSet(int s): parent(new int [s]), size(new int[s]), sz(s)
    {
        //making every node its own parent, and initializing sizes
        for(int i = 0; i<s; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    //method to do union by rank
    void unionBySize(int a, int b)
    {
        //finding ultimate parents
        int pa = UltP(a);
        int pb = UltP(b);

        if(pa!=pb)
        {
            if(size[pa]<size[pb])
            {
                //pa has less size, connecting it to pb
                parent[pa] = pb;
                size[pb]+=size[pa];
            }
            else
            {
                //pb has less size, connecting it to pa
                parent[pb] = pa;
                size[pa]+=size[pb];
            }
        }
    }

    //method to check if two nodes are connected or not
    bool isConnected(int a, int b)
    {
        return ((UltP(a))==UltP(b));
    }

};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //necessary data structures
        DisjointSet ds(V);
        //will store edges like this: {weight, {node1, node2}}
        priority_queue<pip, vector<pip>, greater<pip>> edges;
        
        //will get the edges from adjacency list
        for(int i = 0; i<V; i++)
        {
            for(auto neigh: adj[i])
            {
                edges.push({neigh[1], {i, neigh[0]}});
            }
        }
        
        int sum = 0;
        
        //now doing union
        while(!(edges.empty()))
        {
            pip edge = edges.top();
            edges.pop();
            
            int wt = edge.first;
            int n1 = edge.second.first;
            int n2 = edge.second.second;
            
            //doing union iff they are not already in same component
            if(!ds.isConnected(n1, n2))
            {
                ds.unionBySize(n1, n2);
                sum+=wt;
            }
        }
        
        return sum;
        
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